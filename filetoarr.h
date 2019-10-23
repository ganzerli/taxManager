#include<string>
#include <vector>

class Filetoarr {
    public:
    std::string* getLines(std::string path);
    int countLines(std::string path);
    std::vector<std::string> fileToVector(std::string path);
    std::vector<std::string> getLinesV(std::string path);
    std::vector<std::string> vectorToFile(std::vector<std::string> v);
    private:
};