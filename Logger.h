//
// Created by leandro on 29/8/19.
//

class Logger {
    private:
        static Logger* instance;
        int level;
        string path;
        bool existsFile(string *fileName)
        int getLevel(string *level);
        Logger();

    public:
        static Logger* getInstance();
        void logMessage(string level, string message);
        void setLevel(int level);
};

/* Null, because instance will be initialized on demand. */
