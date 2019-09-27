//
// Created by sebas on 8/9/19.
//

#include "Logger.h"

/**
 * File Manager helper funcitions.
 */
class FileManager {

public:
    static void createFolderIfItDoesNotExist(const string &path) {
        struct stat sb{};
        if (stat(path.c_str(), &sb) != 0) {
            if (mkdir(path.c_str(), 0777) == -1)
                cerr << "Error :  " << strerror(errno) << endl;
            else
                cout << path << " created." << endl;
        }
    };

    static void createFile(const string &path) {
        ofstream file{path};
    };

    static bool existsFile(const string &path) {
        ifstream infile(path);
        return infile.good();
    };

    static void addLine(const string &path, const string &line) {
        ofstream file;
        file.open(path, ios_base::app | ios_base::out);
        file << line + "\n";
        file.close();
    };
};

/**
 * Actual Logger implementation.
 */

Logger::Logger() :
        level(stringToLevel("DEBUG")),
        logFile(getLogFileName()),
        folder("logs") {
    FileManager::createFolderIfItDoesNotExist(folder);
    log(DEBUG, "Se inicia logger en nivel DEBUG.");
}

void Logger::log(LEVEL level_, const string &message) {
    if (this->level >= level_) {
        string log = getLogDateTime() + " " + levelToString(level_) + " " + message;
        printf("%s\n", log.c_str());
        FileManager::addLine(folder + "/" + logFile, log);
    }
}

string Logger::levelToString(LEVEL level) {

    switch (level) {
        case ERROR:
            return "ERROR";
        case INFO:
            return "INFO";
        case DEBUG:
            return "DEBUG";
    }
    return "Error in levelToString!";
}

LEVEL Logger::stringToLevel(const string& stringLevel) {

    if(stringLevel == "ERROR") {
        return ERROR;
    }else if(stringLevel == "INFO") {
        return INFO;
    }

    return DEBUG;
}

string Logger::getLogDateTime() {
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    stringstream dateTime;
    dateTime << localTime->tm_year + 1900 << "-";
    dateTime << setfill('0') << setw(2) << localTime->tm_mon << "-";
    dateTime << setfill('0') << setw(2) << localTime->tm_mday << " ";
    dateTime << setfill('0') << setw(2) << localTime->tm_hour << ":";
    dateTime << setfill('0') << setw(2) << localTime->tm_min << ":";
    dateTime << setfill('0') << setw(2) << localTime->tm_sec;

    return dateTime.str();
}

string Logger::getLogFileName() {
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    stringstream fileName;
    fileName << localTime->tm_year + 1900 << "-";
    fileName << setfill('0') << setw(2) << localTime->tm_mon << "-";
    fileName << setfill('0') << setw(2) << localTime->tm_mday << " ";
    fileName << setfill('0') << setw(2) << localTime->tm_hour;
    fileName << setfill('0') << setw(2) << localTime->tm_min;
    fileName << setfill('0') << setw(2) << localTime->tm_sec << ".log";

    return fileName.str();
}

void Logger::setLevel(const string& newLevel) {
    if (newLevel != "DEBUG" && newLevel != "INFO" && newLevel != "ERROR"){
        log(ERROR, "Nivel de logger invalido: " + newLevel + ". Se mantiene el nivel de log en DEBUG.");
    }else{
        if(levelToString(level) != newLevel){
            level = stringToLevel(newLevel);
            log(INFO, "Se cambia nivel de logger a " + newLevel); // No tiene sentido esta linea
        }
    }
}