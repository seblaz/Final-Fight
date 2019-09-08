#include <string>
using namespace std;

class FileManager {
    public:
        void createFile(string fullPath);
        bool existsFile(string fullPath);
        void addLine(string path, string line);
};
