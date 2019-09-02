//
// Created by leandro on 29/8/19.
//

class Logger {
    private:
        static Logger* instance;
        FileManager* manager;
        int level;
        string path;
        string levels [3];
        int getLevel(string *level);
        Logger();

    public:
        static Logger* getInstance();
        void logMessage(string level, string message);
        void setLevel(string level);
};