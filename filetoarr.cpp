#include"Filetoarr.h"
#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

string* Filetoarr::getLines(string path){
    // open file and return array

// init input file stream
ifstream file(path);
// count size of array
int linesNum = this->countLines(path);

//cout << "n //" << linesNum << "lines in file"<< path <<endl;
    static string rows[254];
if (file.is_open()) {
    std::string line;
    std::string templine;
    int counter = 0;
    while (getline(file, line)) {
        // using printf() in all tests for consistency
        //printf("%s", line.c_str());
        templine = line.c_str();
        rows[counter] = templine; 
        counter++;
    }
    file.close();
}else{
    cout << "unable to open file:" << path << endl;
}
    return rows;
}


vector<string> Filetoarr::getLinesV(string path){
    vector<string> output;
    string line;
    string templine;
    // init input file stream
    ifstream file(path);

    if (file.is_open()) {
        while (getline(file, line)) {
            templine = line.c_str();
            output.push_back(templine); 
        }
        file.close();
    }else{
        cout << "unable to open file:" << path << endl;
    }
        return output;
}


// not usable in c++
int Filetoarr::countLines(string path){
    static int num = 0;
    std::ifstream file(path);
    if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
        num++;
    }
    file.close();
    }else{
         std::cout << "unable to open file:" << path <<endl;
    }
    return num;
}

vector<string> Filetoarr::fileToVector(string path){
    vector<string> stringVector;
    ifstream file(path);

        if (file.is_open()) {
            std::string line;
            std::string templine;
         
            while (getline(file, line)) {
                templine = line.c_str();
                stringVector.push_back(templine);
            }
            file.close();
        }else{
            cout << "unable to open file:" << path << endl;
        }
    return stringVector;
};    

vector<string> Filetoarr::vectorToFile(vector<string> v){
        ofstream outfile;
        outfile.open("./TEST/login.txt");
    //open file
    for (auto it = v.begin(); it != v.end(); ++it){ 
        cout << ' ' << *it << endl; 
        outfile << *it << endl;
    }
        outfile.close();
    //close fie
    return v;
};