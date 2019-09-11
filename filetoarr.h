#include<string>
#include <vector>

class Filetoarr {
    public:
    std::string* getLines(std::string path);
    int countLines(std::string path);
    std::vector<std::string> arrToVector(std::string path);
    private:
};