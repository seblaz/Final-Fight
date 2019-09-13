//
// Created by Leandro on 12/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/XmlReader.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


TEST(XmlReader, GetAttributes) {

    map<string, vector<string>> attributes;

    vector <string> positionsCuchillos;
    positionsCuchillos.push_back("escenario");
    positionsCuchillos.push_back("objetos");
    positionsCuchillos.push_back("cuchillos");
    positionsCuchillos.push_back("cantidad");

    vector <string> debugLevel;
    debugLevel.push_back("debug");
    debugLevel.push_back("level");

    attributes["cantidadCuchillos"] = positionsCuchillos;
    attributes["debugLevel"] = debugLevel;

    XmlReader *reader = new XmlReader();

    map<string, string> result = reader->ReadXml(attributes);

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result["cantidadCuchillos"], "4");
    EXPECT_EQ(result["debugLevel"], "ERROR");
}

TEST(XmlReader, AttributeNotFound) {

    map<string, vector<string>> attributes;

    vector <string> debugLevel;
    debugLevel.push_back("notFound");
    debugLevel.push_back("level");

    attributes["debugLevel"] = debugLevel;

    XmlReader *reader = new XmlReader();

    map<string, string> result = reader->ReadXml(attributes);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result["debugLevel"], "");
}