#include "login.h"
#include <iostream>
// mkdir
#include <stdio.h>
#include <io.h>
//check crate folder
#include <sys/types.h>
#include <sys/stat.h>

struct stat info;
using namespace std;

string Login::getName(){
    name = "name the name";
    return name;
}

// if there is no file create file, if username not in write in and retourn status
string Login::checkUsername(){
    // if folder does not exist create folder
    string username;
    const char *dirPathname = "./TEST";
    int found = 0;
    
    if( stat( dirPathname, &info ) != 0 ){
        // NOT ACCESSIBLE FOLDER FOLDER DOES NOT EXISTS
        printf( "cannot access %s , creating folder \n", dirPathname );
        //create folder
        if(mkdir(dirPathname) != 0){
            printf( " folder created in %s \n", dirPathname );
            found++;
        }
        
    }else if( info.st_mode & S_IFDIR ) { 
        // FOLDER EXISTS 
        printf( "%s is a directory\n", dirPathname );
        found++;
    }else{
        // NOTHING..
        printf( "%s is no directory\n", dirPathname );
    }

    // if folder exists check file
    if(found > 0 && found <3){
        cout << "chekcing for file" << endl;
              //check for file
    if(true){
        // file found
        found++;
    }else{
        //create file if possible go further
        found++;
        }
    }

        // if/ when file and directory exists ask for confirm and add

    if(found > 1){
        // write to the file
    }
    //file not existing create ask for confirm write and set name
    
    return username;
}