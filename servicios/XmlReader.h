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
        map<string, string> ReadXml(map<string, vector<string>> attributes);

    private:
        DOMNode *getNode(DOMNode *pNode, string basicString);
        string getValue(vector<string> route, DOMNode *rootElement);
};