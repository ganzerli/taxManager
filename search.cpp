#include"search.h"
#include"filetoarr.h"
#include"datum.h"
#include "referenceonkruider.h"

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
     //   cout << existingFiles[0] << "vector to retourn positoin 0" << endl;
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

int Search::getMenuInput(string filepath){
    // get user input 
    Referenceonkruider onkruidr;
    vector<string> onkrVec;
    filepath += "/DB.txt";
    onkrVec = onkruidr.onkruidReference(filepath);
    const int onkruidetSize = onkrVec.size();
    
    int input = 1;
    cin.clear();
    cout << "search data from >>"<< endl;
    for(string i : onkrVec){
        cout << input << ") " << i << "   ";
        input ++;
    }
    
    input = 0;
    cout << endl;
    cout << "select number 1 - " << onkruidetSize << endl;
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

int Search::printValues(vector<vector<string>> allDays, int userInput , string filepath){
    vector<string> dayVect;
    string date;
    ////string options[] = {"DATE","BILL","NOTES","EXPENSES","OTHER"};

    Referenceonkruider onkruidr;
    vector<string> onkrVec;
    filepath += "/DB.txt";
    onkrVec = onkruidr.onkruidReference(filepath);
    const int onkruidetSize = onkrVec.size();

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
                // iterate throught ar//ray of options
                 for(int i=0; i < onkruidetSize; i++){
                    // print element in arr
                    cout << onkrVec[i] << " //>> "<< dayVect[i] <<endl;
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
        bool found = false;
    //iteate for the days
    // have a vectorvector to save the result and print..
        vector<vector<string>> vecWordFound;
        
        for(vector<vector<string>>::iterator it = allDays.begin(); it != allDays.end(); ++it){
            dayVect = *it;
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
                    cout << onkrVec[index] << "  >=>  "<< part << endl;
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
       // cout << "searching in "<< *it << "  ..word.. " <<word<< endl;
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
                        increment = 0;
                    }

                    //cout << "temp string " <<  tempString << endl;
                   // works also if part of the word, makelik same with, and next char is empty then is not only part 
                    if(tempString == word){
                        // EXIT ALL RETURN OK
                        result = 1;
                        cout << "WORD " <<  word <<" FOUND !!" << endl;
                        tempString == "";
                    }
                increment++;
                }
                // char in sentence not in the word
                tempString = "";
                // search word from begin
                increment = 0;
            }
            // index op sentence increase
            index++;
        }
    return result;
}

vector<vector<string>> Search::change( vector<vector<string>>allDays, int userInput , string filepath){
     vector<vector<string>> month;
      int result = 0;
      Datum datum;
      bool pass = false;
      string userInputCin;
      vector<string> day;
      //string options[] = {"DATE","BILL","NOTES","EXPENSES","OTHER"};
        // reference onkruider
        Referenceonkruider onkruidr;
        vector<string> onkrVec;  
        filepath += "/DB.txt";
        onkrVec = onkruidr.onkruidReference(filepath);
        const int onkruidetSize = onkrVec.size();
        //

      while(!pass){
        cin.clear();
        cout << "Change datum.." << endl;
        cout << "ENTER DATUM FROM SELECTED: format   dd-mm-yyyy" << endl;
        cin >>userInputCin;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "number selected  " <<userInputCin << endl;
        // needed 
        // get month vector , save file with same end of datum . return vector<days<day>>
        // check if datum
        if(datum.ifDatum(userInputCin) == 1){
            pass = true;
        }else{
            pass = false;
        }
    }
    // get end of datum to open file
    
    string monthName = userInputCin.substr(3,9);
    int indexDatumInMonth =0;
    int i = 0;
    // iterate in vector and keep the month
    for(vector<vector<string>>::iterator it = allDays.begin(); it != allDays.end(); ++it){
        // get the month in a vector
        day = *it;
        if(day[0].substr(3,9) == monthName){
            cout << day[0] << " is in the month " << monthName << endl;
            
        ////
        //
            if(day[0] == userInputCin){
                // change user input positiion in vector
                string userInputCin;
                cin.clear();
                cout << "change value of" << day[0] << endl;
                cout << "enter new value for " << onkrVec[userInput - 1]<< endl;
                getline(cin, userInputCin);
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "changed value in " << onkrVec[userInput - 1] << "  AS  " <<userInputCin << endl;
                day[userInput - 1] = userInputCin;
                month.push_back(day);
            }else{
                month.push_back(day);
                // no foud send feedback
            }
            i++;
        }
        
    }

    cout << "printing month  "<< monthName << endl;
    for(vector<vector<string>>::iterator it = month.begin(); it != month.end(); ++it){
        day = *it;
        cout << "value for month"<< monthName << " datum " << day[0] << "value for " <<onkrVec[userInput-1] << " is  " << day[userInput-1] << endl;
    }
  
    return month;
}