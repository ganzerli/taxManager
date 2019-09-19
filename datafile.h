#include<string>
#include<vector>

class Datafile {
    public:
    int input();
    int checkFile(std::string filepath);
    int createFile(std::string filepath , std::string line);
    std::string dataToString(std::vector<std::string> userInput);
    std::vector<std::string> userInput();
    std::vector<std::string> fileToVector(std::string path);
    std::vector<std::string> vectorToFile(std::vector<std::string> v);
    private:
};