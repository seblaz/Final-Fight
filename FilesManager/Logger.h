#include "FileManager.h"
#include <string>
using namespace std;

class Logger {
    private:
        static Logger* instance;
        static FileManager* fileManager;
        static string path;
        static int level;
        static string levels [3];
        int getLevel(string level);
        static string getFileDateTime();
        static string getLogDateTime();
        Logger();

    public:
        static void Destroy();
        static Logger* Instance();
        void logMessage(string level, string message);
        void setLevel(string level);
};