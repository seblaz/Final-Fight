#include <stddef.h>
#include <ctime>
#include "Logger.h"

using namespace std;

Logger* Logger::instance = NULL;

FileManager* Logger::fileManager = new FileManager();
string Logger::path = "Files";
int Logger::level = 2;
string Logger::levels [3] = { "ERROR", "INFO","DEBUG"};

Logger::Logger() {}

void Logger::Destroy() {
    delete instance;
    delete fileManager;
}

Logger* Logger::Instance() {
    if (instance == NULL) {
        instance = new Logger();

        string dateTime = getFileDateTime();
        string fullPath = path + "/" + dateTime + ".log";

        if (!instance->fileManager->existsFile(fullPath)){
            fileManager->createFile(fullPath);
            path = fullPath;
        }
    }

    return instance;
}


void Logger::logMessage(string level, string message) {

    try {
        int messageLevel = getLevel(level);

        if (this->level >= messageLevel){
            string newLine = getLogDateTime() + " " + level + " " + message;
            this->fileManager->addLine(this->path, newLine);
        }
    }
    catch (exception e){
        logMessage("ERROR", "Se intento loguear con error.");
    }
}

void Logger::setLevel(string level) {
    int newLevel = getLevel(level);

    this->level = newLevel;
}

int Logger::getLevel(string level) {
    int i = 0;
    bool found = false;

    while(i < 3 && !found){
        if(levels[i] == level){
            found = true;;
        }
        i++;
    }

    if (!found){
        throw exception();
    }

    i--;
    return i;
}

string Logger::getFileDateTime(){
    time_t now = time(0);
    tm *localTime = localtime(&now);

    return
        to_string(1 + localTime->tm_mon) +
        to_string(localTime->tm_mday) + "-" +
        to_string(localTime->tm_hour) +
        to_string(localTime->tm_min) +
        to_string(localTime->tm_sec);
}

string Logger::getLogDateTime(){
    time_t now = time(0);
    tm *localTime = localtime(&now);

    return
            to_string(localTime->tm_mday) + "/" +
            to_string(1 + localTime->tm_mon) + " " +
            to_string(localTime->tm_hour) + ":" +
            to_string(localTime->tm_min) + ":" +
            to_string(localTime->tm_sec);
}