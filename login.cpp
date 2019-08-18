#include "login.h"
#include <iostream>
// mkdir
#include <stdio.h>
#include <io.h>
//check crate folder
#include <sys/types.h>
#include <sys/stat.h>

// for fstream
#include <fstream> 

struct stat info;
using namespace std;

string Login::getName(){
    this->name = "name the name";
    return this->name;
}

// if there is no file create file, if username not in write in and retourn status
string Login::checkUsername(){
    // if folder does not exist create folder
    string username;
    const char *dirPathname = "./TEST";
    int found = 0;
    // ifstream opens the file without to overwrite

    ///
        name = "another name";
    //
    
 
    
    if( stat( dirPathname, &info ) != 0 ){
        // NOT ACCESSIBLE FOLDER FOLDER DOES NOT EXISTS
        printf( "cannot access %s , creating folder \n", dirPathname );
        //create folder
        if(mkdir(dirPathname) == 0){
            printf( " folder created in %s \n", dirPathname );
            system("pause");
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
    if(found > 0 && found < 3){
        cout << "chekcing for file" << endl;
        //check for file
        ifstream ifile;
        ifile.open("./TEST/login.txt",ios::out); 

        // crate instance to write to the file
        ofstream outfile;

    if(!ifile || ifile.fail()){
        // file not found create file
        cout << "file does not exist" << endl;

        //array of chars to write 
        char data[100];

        // open a file in write mode.
        outfile.open("./TEST/login.txt");

        cout << "Writing to the file" << endl;
        cout << "Enter Username: "; 

        cin.getline(data, 100);
        
        // write inputted data into the file.
        outfile << data << endl;
        outfile.close();
        found++;

        // log in user
        // needed cast to string from char
        this->name = data;

        printf("logged in as %s \n", data);

    }else{
        // file found open and check for username
        cout << " file .txt exists!!" << endl;
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