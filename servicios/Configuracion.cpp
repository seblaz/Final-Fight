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
#include "Configuracion.h"

using namespace std;
//using namespace xercesc;

Configuracion::Configuracion(const string &path) {
    try {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException &toCatch) {
        // Do your failure processing here
    }

    auto *parser = new xercesc::XercesDOMParser();
    auto *errHandler = (xercesc::ErrorHandler *) new xercesc::HandlerBase();
    parser->setValidationScheme(xercesc::XercesDOMParser::Val_Always);
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
    catch (const xercesc::XMLException &toCatch) {
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
    }
    catch (const xercesc::DOMException &toCatch) {
        char *message = xercesc::XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n";
    }
    doc = parser->getDocument();
}

string Configuracion::getValue(const string &xPath) {
    string finalValue = "";

    xercesc::DOMXPathResult *result = doc->evaluate(
            xercesc::XMLString::transcode(("/configuracion" + xPath).c_str()),
            doc->getDocumentElement(),
            nullptr,
            xercesc::DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
            nullptr);

    if (result->getNodeValue()){
        finalValue = xercesc::XMLString::transcode(result->getNodeValue()->getFirstChild()->getNodeValue());
    }

    return finalValue;
}

int Configuracion::getIntValue(const string &xPath) {
    return stoi(getValue(xPath));
}

float Configuracion::getFloatValue(const string &xPath) {
    return stof(getValue(xPath));
}
