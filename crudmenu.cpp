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
        usrdtaresult = datafile.userInput(filepath);
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
        cout << "option 4) CHANGE .... INSERT WORD DATUM OR BILL AMOUNT" << endl;
        // get datum 
        userInput = search.getMenuInput(filepath);
        // get vector of days
        existingFiles = search.getFilesFrom(filepath);
        allDays = search.getDaysVector(existingFiles);
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        // print values with dates
        search.printValues(daysSearched , userInput , filepath);
    //  @ overrwrite dateSpanDays as MONTH vector
        dateSpanDays = search.change(daysSearched , userInput , filepath);
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
        userInput = search.getMenuInput(filepath);
        // user input
        // open the files with the user input
        // retourn vector with all strings of the days found
        allDays = search.getDaysVector(existingFiles);
        // return vector of vectors of all file possible 
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        //cout << daysSearched[0][0] << "day searched n 1" << endl;

        int ret = search.printValues(daysSearched , userInput , filepath);
        
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
        pathcomplete += "/DB.txt";
        initDB(pathcomplete);
        // 
    }else{
        //data already initialized, get and retpurn path
    }
    // init database


    return pathcomplete;
};

int Crudmenu::initDB(string path){
    int result =0;
    bool userAdd = true;
    ofstream outfile;
    int response;
    string newColumn;
    string column;
    // ask user tables to use .. if 2 exit and print
    outfile.open(path);
    outfile << "date" << endl;

    // ask for keeping the structure for the rekening
        cout << "CHOOSE  1) Keep DB structure for rekenen, 2) insert all DB columns" << endl;
        cin.clear();
        cin >> response;
        cin.clear();
        cin.ignore(10000, '\n');

    if(response == 1){
        outfile << "rekening" << endl;
        outfile << "note" << endl;
        outfile << "expenses" << endl;
        outfile << "other" << endl;
    }
    // add all other columns
    while(userAdd){
        cout << "1) add column to the db 2) exit" << endl;
        cin.clear();
        cin >> response;
        cin.clear();
        cin.ignore(10000, '\n');
        if(response == 1){
            cout << "ADD COLUMN TO DB" << endl;
            userAdd = true;
            cin.clear();
            cin >> newColumn;
            cin.clear();
            cin.ignore(10000, '\n');
            outfile << newColumn << endl;
            result = 1;
        }else{
            userAdd = false;
        }
    }
    outfile.close();
    return result;
}

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