#include"Filetoarr.h"
#include <iostream>
#include <fstream> 

using namespace std;

string* Filetoarr::getLines(string path){
    // open file and return array

// init input file stream
std::ifstream file(path);
// count size of array

int linesNum = this->countLines(path);

cout << "n //" << linesNum << "lines in file"<< path <<endl;

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





    ////
    ///
    //
    //
   static string arr[10];
   arr[0] = "lkd s a  jf";
   arr[1] = "lkleaipon  wdsajf";
   arr[2] = "lkd   sa  j oiuexpmaeff";
   cout << arr[1] << endl;

    return rows;
}


Filetoarr::countLines(string path){
    static int num = 0;
    std::ifstream file(path);
    if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
        num++;
    }
    file.close();
    }else{
        cout << "unable to open file:" << path << endl;
    }
    return num;
}