#include<string>
#include<vector>

class Search {
    public:
    std::vector<std::string> getFilesFrom(std::string path);
    inline bool fileExistence(const std::string& name);
    int getMenuInput();
    std::vector<std::string> getDaysVector(std::vector<std::string> existingFiles);
    std::vector<std::vector<std::string>> getVectorOfAllDaysPossible(std::vector<std::string> daysVector);
    std::vector<std::string> splitString(std::string day);
    int printValues(std::vector<std::vector<std::string>> vectorOfAllDays, int userInput);
    std::vector<std::string> searchWord(std::string word , std::vector<std::string>day);
    int searchWordInString(std::string word , std::string sentence);
};