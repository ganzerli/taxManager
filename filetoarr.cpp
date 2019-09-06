#include"Filetoarr.h"
#include <iostream>
#include <fstream> 

using namespace std;

string* Filetoarr::getLines(string path){
    // open file and return array


std::ifstream file(path);

if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
        // using printf() in all tests for consistency
        printf("%s", line.c_str());
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

    return arr;
}