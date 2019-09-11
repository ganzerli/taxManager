#include"crudmenu.h"
#include"login.h"
#include <iostream>

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

int Crudmenu::switchHandler(int num){
    // needed login for the username
    int selected = 0;
    switch(num) {
    case 1 : cout << "enter data selected.."<< login.getName() << endl; // prints "1"
    // see if there is a folder for the user, if not crate ,
    // and add day and bill
    this->init(loggedUser);
             break;       // and exits the switch
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

    if (checkfolder(pathcomplete)){

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
    int found = 0;
       
    if( stat( dirPathname, &info ) != 0 ){
        // NOT ACCESSIBLE FOLDER FOLDER DOES NOT EXISTS
        printf( "cannot access %s , creating folder \n", dirPathname );
        //create folder
        if(mkdir(dirPathname) == 0){
            printf( " folder created in %s \n", dirPathname );
            system("pause");
            // folder created
            found++;
        }
    }else if( info.st_mode & S_IFDIR ) { 
        // FOLDER EXISTS 
        // printf( "%s is a directory\n", dirPathname );
        found++;
    }else{
        // NOTHING..
        printf( "%s is no directory\n", dirPathname );
    }
    return found;
}

string Crudmenu::getPath(){

    string path;
    return path;
};