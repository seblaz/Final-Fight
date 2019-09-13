//
// Created by leandro on 10/9/19.
//
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "XmlReader.h"

using namespace std;
using namespace xercesc;

string defaultPath = "Configuracion.xml";

map<string, string> XmlReader::ReadXml(map<string, vector<string>> attributes) {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException &toCatch) {
        // Do your failure processing here
    }

    auto *parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional
    auto *errHandler = (ErrorHandler *) new HandlerBase();
    parser->setErrorHandler(errHandler);

    try {
        parser->parse(defaultPath.c_str());
    }
    catch (const XMLException &toCatch) {
        char *message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (const DOMException &toCatch) {
        char *message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n";
    }

    DOMDocument *xmlDoc = parser->getDocument();
    DOMNode *rootElement = xmlDoc->getDocumentElement();

    string rootTitle = XMLString::transcode(rootElement->getNodeName());
    if(rootTitle.compare("configuracion") != 0){
        throw exception();
    }

    map<string, string> result;

    map<string, vector<string>>::iterator it = attributes.begin();

    while (it != attributes.end())
    {
        string key = it->first;
        vector<string> route = it->second;
        string value = "";

        try {
            value = this->getValue(route, rootElement);
        }
        catch (exception e){

        }

        result.insert(pair<string, string>(key, value));

        it++;
    }

    //delete rootElement;
    //delete xmlDoc;
    delete parser;
    delete errHandler;

    return result;
}

string XmlReader::getValue(vector<string> route, DOMNode *rootElement) {
    int position = 0;
    int positionLength = route.size();
    DOMNode* currentNode = rootElement;

    while (position <  positionLength){
        currentNode = this->getNode(currentNode, route[position]);
        position++;
    }

    string finalValue = XMLString::transcode(currentNode->getTextContent());

    return finalValue;
}

DOMNode *XmlReader::getNode(DOMNode *pNode, string nameToFind) {

    DOMNodeList *childrens = pNode->getChildNodes();

    int i = 0;
    bool found = false;
    DOMNode* resultNode;

    while (i < childrens->getLength() && !found){

        DOMNode* currentNode = childrens->item(i);
        string nodeName = XMLString::transcode(currentNode->getNodeName());

        if( currentNode->getNodeType() && currentNode->getNodeType() == DOMNode::ELEMENT_NODE && nodeName.compare(nameToFind) == 0)
        {
            resultNode = childrens->item(i);
            found = true;
        }

        i++;
    }

    if (!found){
        throw exception();
    }

    return resultNode;
}