#include"search.h"
#include"filetoarr.h"
#include"datum.h"
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

vector<vector<string>> Search::getVectorOfAllDaysPossible(vector<string> daysVector){
    // from vector of days from existing files , search and retourn days with content
    vector<vector<string>> daysVec;
    // make days vector
    vector<string> dayVec;
    // iterate throught the vector of strings
    for(vector<string>::iterator it = daysVector.begin(); it != daysVector.end(); ++it) {
        dayVec = splitString(*it);
        // vector of all days in vector
        daysVec.push_back(dayVec);
    }

    return daysVec;
}

vector<vector<string>> Search::vectFromDates(string* twoDates , vector<vector<string>> allDays){
    Datum datum;
    vector<vector<string>>days;
    vector<string> dayVector; 
    int datumf ;
    // compare dates
    for(vector<vector<string>>::iterator it = allDays.begin(); it != allDays.end(); ++it){
        dayVector = *it;
    
        datumf = datum.formatDatum(dayVector[0]);

        // needed dates translate and dates compare
        if(datumf > datum.formatDatum(twoDates[0])  && datumf < datum.formatDatum(twoDates[1]) ){
           cout << "date "<< dayVector[0] <<" between" << twoDates[0] << "  and  " << twoDates[1] << endl;
            days.push_back(dayVector);
        }
    }
    return days;
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
   // cout << "datum found  " << tempDatum <<endl;
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

   // cout << "Last temp string " << tempString << endl;
    
    return vectDay;
}

int Search::printValues(vector<vector<string>> allDays, int userInput){
    vector<string> dayVect;
    string date;
    string options[] = {"DATE","BILL","NOTES","EXPENSES","OTHER"};
    string word;

    if(userInput == 1){
        // ASK DATUM
        cin.clear();
        cout << "enter datum dd-mm-yyyy"<< endl;
        cin >> date;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "datum entered" << date <<endl;
        ////
        bool found = false;
        //iterate throught ALLdays
        for(vector<vector<string>>::iterator it = allDays.begin(); it != allDays.end(); ++it){
            // collect from the vector of all vector of 1 day
           dayVect = *it;
           // CHECK DATUM FROM USER INPUT
            if(date == dayVect[0]){
                // iterate throught array of options
                 for(int i=0; i < (sizeof(options)/sizeof(*options)); i++){
                    // print element in arr
                    cout << options[i] << " //>> "<< dayVect[i] <<endl;
                }
                found = true;
            }
        }
        if(!found){
            cout << " date  " << date << "  not found" << endl;
        }
    }else{ //if not date to search
    // else ask and print the other values with the datums
      cin.clear();
        cout << "enter word to search"<< endl;
        cin >> word;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "datum entered" << word <<endl;
        bool found = false;
    //iteate for the days
    // have a vectorvector to save the result and print..
        vector<vector<string>> vecWordFound;
        
        for(vector<vector<string>>::iterator it = allDays.begin(); it != allDays.end(); ++it){
            dayVect = *it;
            cout << dayVect[userInput-1] << " note or expenses of date " << dayVect[0] << endl;
            // for every day check if the word is in , if that print day or few
            // if word found in other user input display with user input and datum
            // function searching the word
            // if word in , save to vector
            if( searchWord(word , dayVect) == 1){
                // word found in vector..
                //save vector
                found = true;
                vecWordFound.push_back(dayVect);
            }
        }
        // print with preferences
        int index = 0;
        string part;
        if(found){
            //cout << "first in vector //>>" << vecWordFound[0][userInput-1] << endl;
            // print the vector with user preferences
            for(vector<vector<string>>::iterator it = vecWordFound.begin() ; it != vecWordFound.end() ; ++it){
                dayVect = *it;
                // print content of every vector
                cout << "#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@" << endl;
                cout << "printing data of day " << dayVect[0] << endl;
                for(vector<string>::iterator ir = dayVect.begin() ; ir != dayVect.end(); ++ir){
                    part = *ir;
                    cout << options[index] << "  IS  "<< part << endl;
                    index++;
                }
                index = 0;
                cout << "#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@#@" << endl;
                
            }
        }else{
            cout << "word" << word << "  not found !!" << endl;
        }
    }//user input if 1 or else

return 1;
}


int Search::searchWord(string word , vector<string>day){
    string tempString;
    int result = 0;
    // looping in the vector
    for(vector<string>::iterator it = day.begin(); it != day.end(); ++it){
        string daySection = *it;
        // loop in day section
        cout << "searching in "<< *it << "  ..word.. " <<word<< endl;
        if(searchWordInString(word , daySection) == 1 ){
            // add the vector to the results vector
            result = 1 ;
        }
    }
    return result; 
}

int Search::searchWordInString(string word , string sentence){
    int result = 0;
    int index = 0;
    int increment=0;
    string tempString;
    bool found = false;

        for(char& c : sentence) {
            if(c == word[0]){
                // check every char base index until " "
                //"exampleq" sentence
                //"exampler" word
                // c stay the fist char
                found = true;
                while(sentence[index+increment] != ' ' && index+increment < sentence.size() && found){
                    //check the other chars in base of increment to loop throught word
                    if(sentence[index+increment] == word[increment]){
                        found = true;
                        tempString += sentence[index+increment];
                    }else{
                        found = false;
                        tempString ="";
                    }
                   // cout << "temp string " <<  tempString << endl;
                    if(tempString == word){
                    // EXIT ALL RETURN OK
                        result = 1;
                        cout << "WORD " <<  word <<" FOUND !!" << endl;
                        tempString == "";
                    }
                increment++;
                }
                // if the word is same as searched return
                increment = 0;
            }
            // index op sentence increase
            index++;
        }
    return result;
}