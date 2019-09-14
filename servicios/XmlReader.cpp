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
#include <fstream>

#include "Logger.h"
#include "XmlReader.h"

using namespace std;
using namespace xercesc;

XmlReader::XmlReader() {
    XmlReader(this->defaultPath);
}

XmlReader::XmlReader(string path) {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException &toCatch) {
        // Do your failure processing here
    }

    auto *parser = new XercesDOMParser();
    auto *errHandler = (ErrorHandler *) new HandlerBase();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setIncludeIgnorableWhitespace(false);
    parser->setDoNamespaces(true);    // optional

    parser->setErrorHandler(errHandler);

    try {
        ifstream infile(path);

        if(infile.good()){
            parser->parse(path.c_str());
        }else{
            parser->parse(defaultPath.c_str());
        }
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
    doc = parser->getDocument();
}

string XmlReader::getValue(const string &xPath) {
    string finalValue = "";

    DOMXPathResult *result = doc->evaluate(
            XMLString::transcode(("/configuracion" + xPath).c_str()),
            doc->getDocumentElement(),
            nullptr,
            DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
            nullptr);

    if (result->getNodeValue()){
        finalValue = XMLString::transcode(result->getNodeValue()->getFirstChild()->getNodeValue());
    }

    return finalValue;
}