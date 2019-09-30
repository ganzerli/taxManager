#include<string>
#include<vector>

class Search {
    public:
    std::vector<std::string> getFilesFrom(std::string path);
    inline bool fileExistence(const std::string& name);
    int getMenuInput();
    std::vector<std::string> getDaysVector(std::vector<std::string> existingFiles);
    std::vector<std::string> getInputDaysVector(std::vector<std::string> daysVector , int userInput);
    std::vector<std::string> splitString(std::string day);
};