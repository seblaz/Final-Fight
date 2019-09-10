//
// Created by sebas on 9/9/19.
//

#include "gtest/gtest.h"
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace xercesc;


TEST(Xerces, XercesCanParseXML) {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException &toCatch) {
        // Do your failure processing here
    }

    // Do your actual work with Xerces-C++ here.
    auto *parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional
    auto *errHandler = (ErrorHandler *) new HandlerBase();
    parser->setErrorHandler(errHandler);

    string myxml = "<message><warning>Hola, mundo</warning></message>";

    MemBufInputSource src((const XMLByte *) myxml.c_str(), myxml.length(), "dummy", false);

    try {
        parser->parse(src);
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
    DOMElement *elementRoot = xmlDoc->getDocumentElement();
    DOMNodeList *children = elementRoot->getChildNodes();
    const XMLSize_t nodeCount = children->getLength();

    EXPECT_EQ(nodeCount, 1);

    string tag = XMLString::transcode(elementRoot->getTagName());

    EXPECT_EQ(tag, "message");

    // XMLPlatformUtils::Terminate();
    delete parser;
    delete errHandler;
}