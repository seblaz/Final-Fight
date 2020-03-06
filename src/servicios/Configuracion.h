#ifndef FINAL_FIGHT_CONFIGURACION_H
#define FINAL_FIGHT_CONFIGURACION_H

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
#include <list>
#include <mutex>
#include <unordered_map>

using namespace std;

class Configuracion
{

private:
  unordered_map < string, string > cacheStrings;
  unordered_map < string, int >cacheInts;
    unordered_map < string, float >cacheFloats;
  string actualPath = "";
  string defaultPath = "Configuracion.xml";
    xercesc::XercesDOMParser * parser;
    xercesc::ErrorHandler * errHandler;
  mutex m;

public:
    explicit Configuracion (const string & path = "Configuracion.xml");
   ~Configuracion ();
  string getValue (const string & xPath);
  int getIntValue (const string & xPath);
  float getFloatValue (const string & xPath);

  string getValue (const string & xPath, const string & defaultValue);
  int getIntValue (const string & xPath, int defaultValue);
  float getFloatValue (const string & xPath, float defaultValue);
  string getActualPath ();
};

#endif //FINAL_FIGHT_CONFIGURACION_H
