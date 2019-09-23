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

#include "Locator.h"
#include "Configuracion.h"


using namespace std;
//using namespace xercesc;

Configuracion::Configuracion(const string &path) {
    try {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException &toCatch) {
        // Do your failure processing here
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
    }

    parser = new xercesc::XercesDOMParser();
    errHandler = (xercesc::ErrorHandler *) new xercesc::HandlerBase();
    parser->setIncludeIgnorableWhitespace(false);
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
}

Configuracion::~Configuracion() {
    delete parser;
    delete errHandler;
}

string Configuracion::getValue(const string &xPath) {
    XMLCh *tag = xercesc::XMLString::transcode(("/configuracion" + xPath).c_str());

    xercesc::DOMXPathResult *result = parser->getDocument()->evaluate(
            tag,
            parser->getDocument()->getDocumentElement(),
            nullptr,
            xercesc::DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
            nullptr);

    xercesc::XMLString::release(&tag);

    if (!result->getNodeValue()){
        return "";
    }

    char* finalValue = xercesc::XMLString::transcode(result->getNodeValue()->getFirstChild()->getNodeValue());
    result->release();

    std::string returnValue(finalValue);
    xercesc::XMLString::release(&finalValue);
    return returnValue;
}

int Configuracion::getIntValue(const string &xPath) {
    string result = getValue(xPath);
    return stoi(result);
}

float Configuracion::getFloatValue(const string &xPath) {
    string result = getValue(xPath);
    return stof(result);
}

string Configuracion::getValue(const string &xPath, const string &defaultValue) {
    string result = getValue(xPath);
    return result.empty() ? defaultValue : result;
}

int Configuracion::getIntValue(const string &xPath, int defaultValue) {
    string result = getValue(xPath);
    return result.empty() ? defaultValue : stoi(result);
}

float Configuracion::getFloatValue(const string &xPath, float defaultValue) {
    string result = getValue(xPath);
    return result.empty() ? defaultValue : stof(result);
}