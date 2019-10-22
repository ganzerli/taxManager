#include"crudmenu.h"
#include"datafile.h"
#include"login.h"
#include"search.h"
#include"rekenen.h"

#include <iostream>
#include <vector>

// string concatenation
#include <sstream>

// mkdir
#include <stdio.h>
#include <io.h>
//check crate folder
#include <sys/types.h>
#include <sys/stat.h>
// info for folders
//struct stat info;

// crate char arr from string
#include <bits/stdc++.h> 


using namespace std;

int Crudmenu::switchHandler(int num , string username){
        //init variables case 1
        Datafile datafile;
        Search search;
        string fileName = "";
        vector<string> usrdtaresult;
        string filepath ="./DATA/"+ username;
        string toWrite;
        int selected = 0;
        // init variables case 2
        vector<string> existingFiles;
        vector<string> allDays;
        vector<vector<string>> daysSearched;

        // init variables case 3
        vector<string> datumSpan;
        Rekenen rekenen;
        string* dates;
        vector<string> dayVect;
        vector<vector<string>> dateSpanDays; // container
        vector<vector<string>> daysWithBill; // output
        float rekening;
        float expenses;
        // case 4
        int userInput;
        
   
    switch(num) {

    case 1 : 
        cout << "enter data of user "<< username << endl; // prints "1"
        // see if there is a folder for the user, if not crate ,
        if(mkdir("./DATA") == 0){
                //printf( " folder created in ./DATA" );
        }
        // folder will be initialiyed..
        this->init(username);
        // ask data to user
        usrdtaresult = datafile.userInput();
        // from the first input get end of date to use as filename
        fileName = usrdtaresult[0];
        //create filepath
        fileName = fileName.substr(3,7);
        filepath = filepath +'/'+ fileName + ".txt";
        cout << filepath << endl;
        // open file and create if not existing
        if(datafile.checkFile(filepath) != 1){
            // create and write first line FILE DOES NOT EXIST
            cout << "no , file not existing create.." <<endl;
            toWrite = datafile.dataToString(usrdtaresult);
            ofstream outfile;
            outfile.open(filepath);; 
            outfile << toWrite << endl;
            outfile.close();
        }else{
            //if file exists get inside of file and add the record
            toWrite = datafile.dataToString(usrdtaresult);
            datafile.addRecord(filepath, toWrite);
        }

        break;
    case 3 :
       // cout <<"case 3 REKENEN" << endl;
        existingFiles = search.getFilesFrom(filepath);
        allDays = search.getDaysVector(existingFiles);
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        //cout << daysSearched[0][0] << "day searched n 1" << endl;
        //ask datum
        selected = rekenen.getDateMenu();
        if( selected == 0 ){
            cout << "print all days with rekening" << endl;
            dateSpanDays = daysSearched;
        }else{
            // string* with 2 datums string
            dates = rekenen.getDateSpan();
            // return days between 2 dates
            dateSpanDays = search.vectFromDates(dates , daysSearched);
        }
        // PRINT DATES 
        for(vector<vector<string>>::iterator it = dateSpanDays.begin(); it != dateSpanDays.end(); ++it){
                dayVect =  *it;
                rekening = rekenen.ifBill(dayVect[1]);
                expenses = rekenen.ifBill(dayVect[3]);
                if(rekening + expenses < 0.01){
                //    cout << "amount bill not found in  //>>" << rekening << endl;
                //    cout << "and amount expenses not found in  //>>" << expenses << endl;
                }else{
                    // bill found
                //    cout << "amount bill of "<< rekening <<" found in" << rekening << endl;
                //    cout << "and amount expenses " << expenses << endl;
                    daysWithBill.push_back(dayVect);
                }
            }
        // print all datums with bills and expenses
        rekenen.printBill(daysWithBill);
        break;
    case 4 :
        cout << "option 4) change .... INSERT WORD DATUM OR BILL AMOUNT" << endl;
        // get datum 
        userInput = search.getMenuInput();
        // get vector of days
        existingFiles = search.getFilesFrom(filepath);
        allDays = search.getDaysVector(existingFiles);
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        // print values with dates
        search.printValues(daysSearched , userInput);
        cout << "select DATE from available days" << endl;
    //  @ overrwrite dateSpanDays as MONTH vector
        dateSpanDays = search.change(daysSearched , userInput);
        // create string to write as file back form MONTH
        for(vector<vector<string>>::iterator it = dateSpanDays.begin(); it != dateSpanDays.end(); ++it){
            dayVect = *it;
            toWrite += datafile.dataToString(dayVect);
        }
        //create filepath
        cout <<  toWrite << endl;
        filepath+= "/" + dateSpanDays[0][0].substr(3,9)+".txt";
    
        cout << "for file " << filepath << endl;
        // write to file
        datafile.replaceFile(filepath , toWrite);
        break;

    case 2 : 
        //cout << '2' << endl;
        // search for various searchs with class search
        // to have files and filenames
        existingFiles = search.getFilesFrom(filepath);
        //cout << "second file" << existingFiles[1] << endl;
        // path of user, input if datum. datum
        userInput = search.getMenuInput();
        // user input
        // open the files with the user input
        // retourn vector with all strings of the days found
        allDays = search.getDaysVector(existingFiles);
        // return vector of vectors of all file possible 
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        //cout << daysSearched[0][0] << "day searched n 1" << endl;

        int ret = search.printValues(daysSearched , userInput);
        
        break;

    }
    return selected;
};

string Crudmenu::init(string username){
    // if username folder and file does not exist create
        //checkFplder("./DATA")
    // data folder must be already specified
    // find the path for the folder from username
    stringstream strstream;
    strstream << "./DATA/" << username ;
    string pathcomplete = strstream.str();
    
    //cout << checkfolder(pathcomplete) << "from checkfoldrer" << endl;
    //cout << checkfolder("./DATA") << endl;
    
    if (checkfolder(pathcomplete) == 0){
        // create file in the folder created with user tables
        // ask user if keep the rekening and expenses 
        // 
    }else{
        //data already initialized, get and retpurn path
    }
    return pathcomplete;
};

int Crudmenu::checkfolder(string pathname){
    struct stat info;
    //define size of array
    int lengtharray = pathname.length();
    char arrpath[lengtharray + 1];

    // function to translate the string in char array
    strcpy(arrpath, pathname.c_str());

    const char *dirPathname = arrpath;
    int dirPath = 0;

    if( stat( dirPathname, &info ) != 0 ){
        // NOT ACCESSIBLE FOLDER FOLDER DOES NOT EXISTS
        printf( "cannot access %s , creating folder \n", dirPathname );
        //create folder
        if(mkdir(dirPathname) == 0){
            printf( " folder created in %s \n", dirPathname );
            system("pause");
            // folder created
            dirPath++;
        }
    }else if( info.st_mode & S_IFDIR ) { 
        // FOLDER EXISTS 
        dirPath++;
    }else{
        // NOTHING..
        printf( "%s is no directory\n", dirPathname );
    }
    return dirPath;
}

string Crudmenu::getPath(){
return "DATA";
};