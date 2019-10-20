#include<string>
#include<vector>

using namespace std;

class Search {
    public:
    vector<string> getFilesFrom(string path);
    inline bool fileExistence(const string& name);
    int getMenuInput();
    vector<string> getDaysVector(vector<string> existingFiles);
    vector<vector<string>> getVectorOfAllDaysPossible(vector<string> daysVector);
    vector<vector<string>> vectFromDates(string* arr2dates , vector<vector<string>> allDays);
    vector<string> splitString(string day);
    vector<vector<string>> change(vector<vector<string>> vectorOfAllDays, int userInput);
    int printValues(vector<vector<string>> vectorOfAllDays, int userInput);
    int searchWord(string word , vector<string>day);
    int searchWordInString(string word , string sentence);
};