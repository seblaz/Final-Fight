#include <iostream>
#include <fstream>
#include "FileManager.h"

void FileManager::createFile(string fullPath){
    std::ofstream file { fullPath };
}

bool FileManager::existsFile(string fullPath) {
    std::ifstream infile(fullPath);
    return infile.good();
}

void FileManager::addLine(string path, string line){
    ofstream file;
    file.open (path, std::ios_base::app | std::ios_base::out);
    file << line + "\n";
    file.close();
}