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
        string fileName = "lsakdjflksadjflksadjflkasdjf";
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
        
   
    switch(num) {

    case 1 : 
        cout << "enter data selected.."<< username << endl; // prints "1"

        // see if there is a folder for the user, if not crate ,
        if(mkdir("./DATA") == 0){
                printf( " folder created in ./DATA" );
        }
        // folder will be initialiyed..
        this->init(username);
        
        // ask data to user
        // make the file with datum as name
        usrdtaresult = datafile.userInput();
        
        // from the first input get end of date to use as filename
        fileName = usrdtaresult[0];
        fileName = fileName.substr(3,7);
        filepath = filepath +'/'+ fileName + ".txt";

        cout << filepath << endl;
        // open file and create if not existing
        cout << "chekc for file" << filepath << endl;
        
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
        cout <<"case 3 REKENEN" << endl;
        existingFiles = search.getFilesFrom(filepath);
        allDays = search.getDaysVector(existingFiles);
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        cout << daysSearched[0][0] << "day searched n 1" << endl;
        //ask datum
        selected = rekenen.getDateMenu();
        if( selected == 0){
            cout << "print all days with rekening" << endl;
        }else{
            // string* with 2 datums string
            dates = rekenen.getDateSpan();
            // return days between 2 dates
            dateSpanDays = search.vectFromDates(dates , daysSearched);
            for(vector<vector<string>>::iterator it = dateSpanDays.begin(); it != dateSpanDays.end(); ++it){
                dayVect =  *it;
                // @ OVERWRITE int selected
                selected = rekenen.ifBill(dayVect[1]);
                if(selected == 0){
                    cout << "amount bill not found in  //>>" << dayVect[1] << endl;
                }else{
                    // bill found
                    cout << "amount bill of"<< selected <<" found in" << dayVect[1] << endl;
                    daysWithBill.push_back(dayVect);
                }
            }
        }

        // having the dates with bill in vector
        for(vector<vector<string>>::iterator i = daysWithBill.begin(); i != daysWithBill.end(); ++i){
            // @ OVERWRITE dayVect vector<string>
            dayVect =  *i;
            cout << dayVect[0] << "has bill of " << dayVect[1] << endl;
        }
        // print all datums with bills and expenses
        // print after that the amount total of bills and ask to calculate the btw for bill and expenses
        // display and give forecast for amount taxes to pay !!! 
        break;
    case 2 : 
        cout << '2' << endl;
        // search for various searchs with class search
        // to have files and filenames
        existingFiles = search.getFilesFrom(filepath);
        //cout << "second file" << existingFiles[1] << endl;
        // path of user, input if datum. datum
        int userInput = search.getMenuInput();
        // user input
        // open the files with the user input
        // retourn vector with all strings of the days found
        
        allDays = search.getDaysVector(existingFiles);
        // vector allDays works fine
        // return vector of vectors of all file possible 
        daysSearched = search.getVectorOfAllDaysPossible(allDays);
        cout << daysSearched[0][0] << "day searched n 1" << endl;

        int ret = search.printValues(daysSearched , userInput);

        // pass user unput and vector to print 
        
        // searching
            // for open files
            // of all files split all days
                //split the days in vector of strings
                //return from the file a vector of days
            
            // get the vector of strings from the file and check which contains the text
                //add to the vector of days to get
            
            //return a vector with the days containing the info
            // search.print(input , dates allemal) prints things in decided order or interest of user
        break;

    }

    return selected;
};

string Crudmenu::init(string username){
    // if username folder and file does not exist create
    // data folder must be already specified
    // find the path for the folder from username
    stringstream strstream;
    strstream << "./DATA/" << username ;
    string pathcomplete = strstream.str();
    
    cout << checkfolder(pathcomplete) << "from checkfoldrer" << endl;

    if (checkfolder(pathcomplete) == 0){

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