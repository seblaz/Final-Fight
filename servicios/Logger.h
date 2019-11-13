//
// Created by sebas on 8/9/19.
//

#ifndef FINAL_FIGHT_LOGGER_H
#define FINAL_FIGHT_LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/stat.h>
#include <cstring>

using namespace std;

enum LEVEL {ERROR, INFO, DEBUG};

class Logger {

private:
    LEVEL level;
    string logFile;
    string folder;

    static string getLogDateTime();
    static string getLogFileName();
    static string levelToString(LEVEL);
    static LEVEL stringToLevel(const string&);

public:
    explicit Logger(const string& prefijo);
    void log(LEVEL level_, const string& message);
    void setLevel(const string& level);
};


#endif //FINAL_FIGHT_LOGGER_H
