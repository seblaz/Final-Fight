//
// Created by leandro on 1/9/19.
//
#include <iostream>
#include <fstream>
#include "FileManager.h"

void createFile(string fullPath){
    std::ofstream file { fullPath };
}

bool existsFile(string fullPath) {
    std::ifstream infile(fullPath);
    return infile.good();
}

void addLine(string path, string line){
    ofstream file;
    file.open (path);
    file << line + "\n";
    file.close();
}