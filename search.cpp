#include"search.h"
#include"filetoarr.h"
#include <sstream>
#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

using namespace std;

vector<string> Search::getFilesFrom(string path){
    vector<string> possibleNames;
    vector<string> existingFiles;
    string possibleStringDate;
    const int MONTHSLIMIT = 12;
    const int YEARSENDDATE = 2035;
    const int YEARBEGINDATE = 2019;
    // have a yro time .. of .... ... now..
    std::stringstream sstm;
 
    for(int i = YEARBEGINDATE; i < YEARSENDDATE; i++){
        for(int j = 1; j <= MONTHSLIMIT; j++){
            // if file < 10 add a 0 on front
            if(j < 10){
                // 6. with IOStreams
                sstm <<'0' << j << '-' << i << ".txt" ;
                possibleStringDate = sstm.str();
                //cout <<"possible date , and possinble files  "<< possibleStringDate << endl;
                sstm.str("");
                possibleNames.push_back(possibleStringDate);
                // empty string 
            }else{
           //
                sstm << j << '-' << i << ".txt" ;
                possibleStringDate = sstm.str();
                //cout <<"possible date , and possinble files  "<< possibleStringDate << endl;
                sstm.str("");
                possibleNames.push_back(possibleStringDate);
            }
        }
        // open file if opens return insert datum in vector
    }
        
        for(vector<string>::iterator it = possibleNames.begin(); it != possibleNames.end(); ++it) {
            // cout <<"in vector "<< *it << endl;
            if(fileExistence(path+"/"+*it) ){
                //cout<< "file" << path << "/" << *it << "exists !!!!!!!!!!!!!!!!!!!" << endl;
                existingFiles.push_back(path+"/"+*it);
            }else{
               // cout<< "file" << path << "/" << *it << " does not exist" << endl;
            }
        }
        // check files in vecotor
        cout << existingFiles[0] << "vector to retourn positoin 0" << endl;
    // needed .. search in months, of the years, bidimensional loop
    //  YeRS.. from the date
    // needed function translating strings to int

    return existingFiles;
}

inline bool Search::fileExistence(const string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

int Search::getMenuInput(){
    // get user input 
    int input;
    cin.clear();
    cout << "search data from >> 1)datum  2)bill  3)notes  4)expenses  5)other" << endl;
    cout << "select number 1 - 5"<< endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "number selected  " << input << endl;
    return input;
}

vector<string> Search::getDaysVector(vector<string> existingFiles){
    vector<string> daysVector;
    // open files , split content , add in vector
    Filetoarr filetoarr; 
    char ch;
    string tempString;
    // iterate in the vector
    for(vector<string>::iterator it = existingFiles.begin(); it != existingFiles.end(); ++it) {
        // filetovector returns a vector of lines, month file is in a string together
        string fileContent = filetoarr.fileToVector(*it)[0];
        // build a string with the files contents , to then split
        for(string::size_type i = 0; i < fileContent.size(); ++i) {
            ch = fileContent[i];
            tempString = tempString + ch;
        }
    }
    //cout << tempString << endl;
    string line;
     
       for(string::size_type i = 0; i < tempString.size(); ++i) {
            line = line+tempString[i];
            if(tempString[i-2] == '<' && tempString[i-1] == '=' && tempString[i] == '/'){
                cout << line << endl;
                daysVector.push_back(line);
                line ="";
            }
        }
    
    return daysVector;
}

vector<string> Search::getInputDaysVector(vector<string> daysVector , int userInput){
    // from vector of days from existing files , search and retourn days with content
    vector<string> daysVec;


    return daysVec;
}