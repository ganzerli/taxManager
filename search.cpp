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
    vector<vector<string>> daysVec;
    // split the vecotr string , get datum and user input
    if (userInput == 1){
        // datum display all data of day
        //ask datum
        cin.clear();
        string date;
        cout << "enter datum dd-mm-yyyy"<< endl;
        cin >> date;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "datum entered" << date <<endl;
        //string in vector returns the position
         vector<string> dayVec;
         string tempDay;
        // iterate throught the vector of strings
         for(vector<string>::iterator it = daysVector.begin(); it != daysVector.end(); ++it) {
            dayVec = splitString(*it);
            // vector of all days in vector
            daysVector.push_back(dayVec);
        }
        //days vector.. search for date and return


        cout << "day vector index 0  " << dayVec[0] << endl;
    }else{// not a datum
        cout << "research for other type" << endl;
    }

    return daysVec;
}

vector<string> Search::splitString(string day){
    // from day string gives the vector of the day
    vector<string> vectDay;
    string tempString;
    string tempDatum;
    char ch;
    
    // cut out beginning ,
    //get datum, saving chars
    for(int i=3; i< 13; ++i){
        tempDatum = tempDatum + day[i];
    }
    cout << "datum found  " << tempDatum <<endl;
    vectDay.push_back(tempDatum);
    tempDatum ="";

    // i = 17 cutting the 13 chars of beginning and datum, and the following <//>
    for(string::size_type i = 17; i < day.size(); ++i) {
        // continue saving chars and save temp string in vector when <//> or <=/
        //found the end exit
        tempString = tempString + day[i];
        // if <//> push in vector element and clear string
        if(day[i+1] =='<' && day[i+2] =='/' && day[i+3] =='/' && day[i+4] =='>'){
            //save tempString and count further
            vectDay.push_back(tempString);
           // cout << "adding in vector //==>  " << tempString << endl;
            tempString = "";
            i = i+4;
        }
    }
    // take away the last chars
    tempString = tempString.substr(0,tempString.size()-3);
    vectDay.push_back(tempString);

    cout << "Last temp string " << tempString << endl;
    
    return vectDay;
}