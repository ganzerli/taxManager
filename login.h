#include<string>

class Login {
    public:
    std::string getName();
    std::string checkUsername();
    private:
    std::string name = "NULL";
    int setName(std::string nametoset);
    
};