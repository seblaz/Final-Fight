//
// Created by sebas on 25/8/19.
//
#include <stdio.h>
#include "FilesManager/Logger.h"
using namespace std;

int main() {
    FileManager* manager = new FileManager();

    Logger::Instance()->logMessage("ERROR", "Hola buen dia");
    /*Logger::Instance()->logMessage("ERROR", "Alto error");
    Logger::Instance()->logMessage("DEBUG", "Esto es debug");
    Logger::Instance()->logMessage("jajaj", "Alto error");

    Logger::Instance()->setLevel("ERROR");
    Logger::Instance()->logMessage("ERROR", "Este debe ir");
    Logger::Instance()->logMessage("DEBUG", "Este no");

    Logger::Destroy();*/
    return 0;
}