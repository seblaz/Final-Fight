//
// Created by leandro on 29/8/19.
//

#include "Logger.h"
static Logger getLogger();
void log(string level, string message);
void setLoggerLevel(string level);

Logger* Logger::logger = NULL;
int Logger::level = 3;
string Logger::path = "";

bool existsFile()
{
    std::ifstream infile(this.path);
    return infile.good();
}

Logger::Logger() {

}

Logger* Logger::getInstance()
{
    if (logger == NULL)
    {
        logger = new Logger();
    }

    return logger;
}

void Logger::setLevel(int level) {
    if(level > 1 && level <= 3){
        this.level = level;
    }
}

void Logger::logMessage(string level, string message) {
    int messageLevel = this.getLevel(level);

    if (this.level >= messageLevel){

    }
}