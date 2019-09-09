//
// Created by sebas on 8/9/19.
//

#ifndef MYAPP_LOGGER_H
#define MYAPP_LOGGER_H

#include <string>

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

public:
    explicit Logger(LEVEL level);
    void log(LEVEL level_, const string& message);
};


#endif //MYAPP_LOGGER_H
