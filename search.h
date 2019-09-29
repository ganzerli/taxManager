#include<string>
#include<vector>

class Search {
    public:
    std::vector<std::string> getFilesFrom(std::string path);
    inline bool fileExistence(const std::string& name);
};