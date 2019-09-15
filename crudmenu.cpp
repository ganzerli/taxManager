#include"crudmenu.h"
#include"datafiles.h"
#include"login.h"

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
    // needed login for the username
    Login login;
    Datafiles datafile;
    int selected = 0;
    switch(num) {
    case 1 : cout << "enter data selected.."<< username << endl; // prints "1"
  
    // see if there is a folder for the user, if not crate ,
    // and add day and bill
    this->init(username);
    // folder will be initialiyed..
    // get data of day
    login.getName();
    datafile.getInput();
    // if folder exists ask data
    //needed
    // get path from init.. return path ,crete folder in case not existing
    //a file.. .. named ..-------v
    //a something to get the data from user
    // a something to store data
    // make the file with datum as name
    // wirte in file




             break;
    case 2 : cout << '2' << endl;
    // search for various searchs with class search
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