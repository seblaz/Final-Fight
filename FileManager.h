//
// Created by leandro on 1/9/19.
//

#ifndef MYAPP_FILEMANAGER_H
#define MYAPP_FILEMANAGER_H


class FileManager {
    public:
        void createFile(string fullPath);
        bool existsFile(string fullPath);
        void addLine(string path, string line);
};


#endif //MYAPP_FILEMANAGER_H
