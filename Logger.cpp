//
// Created by leandro on 29/8/19.
//

#include "Logger.h"

Logger* Logger::instance = NULL;
FileManager* Logger:manager = new FileManager();
int Logger::level = 2;
string Logger::path = "";
string levels [3] = { "ERROR", "INFO","DEBUG"};

Logger::Logger() {
    string time = this.getDateTime();
    string fullPath = this.path + "/" + time + ".log";

    if (!this.fileManager.existsFile(fullPath)){
        this.fileManager.createFile(fullPath);
    }
}

Logger* Logger::getInstance() {
    if (instance == NULL) {
        instance = new Logger();
    }

    return logger;
}

void Logger::logMessage(string level, string message) {
    int messageLevel = this.getLevel(level);

    if (this.level >= messageLevel){
        string newLine = this.getDateTime() + " " + this.levels[this.level] + " " + message;
        this.fileManager.addLine(this.path, newLine);
    }
}

int Logger:getLevel(string level){
    int i = 0;
    bool found = false;

    while(i < 3 && !found){
        if(levels[i] == level){
            found = true;;
        }
    }

    return i;
};

void Logger::setLevel(string level) {
    int newLevel = this.getLevel(level);

    this.level = newLevel;
}
