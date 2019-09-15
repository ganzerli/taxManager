
using namespace std;
#include<string>
#include<vector>

class Datafiles {
    public:
    std::string* getLines(std::string path);
    std::vector<std::string> getInput();
    std::vector<std::string> fileToVector(std::string path);
    std::vector<std::string> vectorToFile(std::vector<std::string> v);
    private:
};