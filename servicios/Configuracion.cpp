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
#include <list>

#include "Locator.h"
#include "Configuracion.h"


using namespace std;
//using namespace xercesc;

Configuracion::Configuracion(const string &path) {
    try {
        xercesc::XMLPlatformUtils::Initialize();

        parser = new xercesc::XercesDOMParser();
        errHandler = (xercesc::ErrorHandler *) new xercesc::HandlerBase();
        parser->setIncludeIgnorableWhitespace(false);
        parser->setErrorHandler(errHandler);

        ifstream infile(path);

        if(infile.good()){
            bool empty = ( infile.get(), infile.eof() );
            if(!empty){
                parser->parse(path.c_str());
                actualPath = path;
            }else{
                Locator::logger()->log(ERROR, "Archivo de configuracion vacio. Se abre archivo por default");
                parser->parse(defaultPath.c_str());
                actualPath = defaultPath;
            }
        }else{
            Locator::logger()->log(ERROR, "Archivo de configuracion no encontrado. Se abre archivo por default");
            parser->parse(defaultPath.c_str());
            actualPath = defaultPath;
        }

        cargarUsuarios();
    }
    catch (const xercesc::SAXException &toCatch) {
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());

        string errorMsg(message);

        Locator::logger()->log(ERROR, "Error en archivo de configuracion. Mensaje: " + errorMsg + ". Se abre archivo por default.");
        try {
            parser->parse(defaultPath.c_str());
        } catch (const xercesc::SAXException &toCatch) {

            Locator::logger()->log(ERROR, "Error en archivo de configuracion por default. Mensaje: " + errorMsg + ". Se termina el programa.");
            throw std::invalid_argument( "Xml por defecto invalido" );
        }
        actualPath = defaultPath;
    }
    catch (...) {
        Locator::logger()->log(ERROR, "Error en archivo de configuracion por default. Se termina el programa.");
        throw std::invalid_argument( "Xml por defecto invalido" );
    }
}

Configuracion::~Configuracion() {
    delete parser;
    delete errHandler;
}

string Configuracion::getValue(const string &xPath) {
    lock_guard<mutex> lock(m);
    XMLCh *tag = xercesc::XMLString::transcode(("/configuracion" + xPath).c_str());

    xercesc::DOMXPathResult *result = parser->getDocument()->evaluate(
            tag,
            parser->getDocument()->getDocumentElement(),
            nullptr,
            xercesc::DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
            nullptr);

    xercesc::XMLString::release(&tag);

    if (!result->getNodeValue())
        return "";

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

string Configuracion::getActualPath(){
    return actualPath;
}

void Configuracion::cargarUsuarios() {
    XMLCh *tag = xercesc::XMLString::transcode(("/configuracion/usuarios"));

    xercesc::DOMXPathResult *result = parser->getDocument()->evaluate(
            tag,
            parser->getDocument()->getDocumentElement(),
            nullptr,
            xercesc::DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
            nullptr);

    xercesc::XMLString::release(&tag);

    if (!result->getNodeValue())
        throw exception();

    xercesc_3_2::DOMNodeList* usuarios = result->getNodeValue()->getChildNodes();

    for( int i = 0; i < usuarios->getLength(); i++ ) {
        xercesc_3_2::DOMNode *currentNode = usuarios->item(i);
        if (currentNode->getNodeType() &&  currentNode->getNodeType() == xercesc_3_2::DOMNode::ELEMENT_NODE)
        {
            if (xercesc_3_2::XMLString::equals(currentNode->getNodeName(), xercesc_3_2::XMLString::transcode("usuario"))) {
                xercesc_3_2::DOMNodeList* hijosUsuarios = currentNode->getChildNodes();

                string configUser;
                string configPass;

                for( int j = 0; j < hijosUsuarios->getLength(); j++ ) {
                    if (hijosUsuarios->item(j)->getNodeType() &&  hijosUsuarios->item(j)->getNodeType() == xercesc_3_2::DOMNode::ELEMENT_NODE)
                    {
                        if (xercesc_3_2::XMLString::equals(hijosUsuarios->item(j)->getNodeName(), xercesc_3_2::XMLString::transcode("username")))
                            configUser = xercesc::XMLString::transcode(hijosUsuarios->item(j)->getTextContent());

                        if (xercesc_3_2::XMLString::equals(hijosUsuarios->item(j)->getNodeName(), xercesc_3_2::XMLString::transcode("password")))
                            configPass = xercesc::XMLString::transcode(hijosUsuarios->item(j)->getTextContent());
                    }
                }

                map<string, string> nuevoUsuario;
                nuevoUsuario["username"] = configUser;
                nuevoUsuario["password"] = configPass;
                this->usuariosCargados.push_back(nuevoUsuario);
            }
        }
    }
}

bool Configuracion::isUserOk(string user, string pass){
    bool encontrado = false;

    std::list<map<string, string>>::iterator it;
    for (it = usuariosCargados.begin(); it != usuariosCargados.end(); ++it){
        map<string,string> usuario = it.operator*();

        if(usuario["username"] == user && usuario["password"] == pass){
            encontrado = true;
        }
    }

    return encontrado;
}