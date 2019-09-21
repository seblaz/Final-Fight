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

using namespace std;

class Configuracion {

private:
    string defaultPath = "ConfiguracionOld.xml";
    xercesc::XercesDOMParser *parser;
    xercesc::ErrorHandler *errHandler;

public:
    explicit Configuracion(const string &path = "Configuracion.xml");
    ~Configuracion();
    string getValue(const string& xPath);
    int getIntValue(const string& xPath);
    float getFloatValue(const string& xPath);

};