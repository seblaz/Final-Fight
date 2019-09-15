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
using namespace xercesc_3_2;

class XmlReader {

public:
    explicit XmlReader(const string &path = "Configuracion.xml");
    string getValue(const string& xPath);

private:
    DOMDocument *doc;
    string defaultPath = "Configuracion.xml";
};