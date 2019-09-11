#include "login.h"
#include "filetoarr.h"

#include <iostream>
// mkdir
#include <stdio.h>
#include <io.h>
//check crate folder
#include <sys/types.h>
#include <sys/stat.h>

// class to get array of line in file func(path) return array

// for fstream
#include <fstream> 

struct stat info;
using namespace std;

string Login::getName(){
    //cout << "name is ... .. . . " << this-> name << endl;
    return this-> name;
}

int Login::setName(string nametoset){
    this->name = nametoset;
    return 1;
}


// if there is no file create file, if username not in write in and retourn status
string Login::checkUsername(){
    // if folder does not exist create folder
    name = "NULL";

    const char *dirPathname = "./TEST";
    int found = 0;
       
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
     //   printf( "%s is a directory\n", dirPathname );
        found++;
    }else{
        // NOTHING..
        printf( "%s is no directory\n", dirPathname );
    }


    //  FILE   FILE   FILE   FILE   FILE   FILE   FILE
    // if folder exists check file
    if(found > 0 && found < 3){
         // init userlist
         Filetoarr userList;

        cout << "chekcing for file" << endl;
        //check for file
        ifstream ifile;
        ifile.open("./TEST/login.txt",ios::out); 

        // crate instance to write to the file
        ofstream outfile;

    if(!ifile || ifile.fail()){
        // file not found create file and add a user
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
        name = data;
        printf("logged in as %s \n", data);
    }else{ // if file exists
        // file found open and check for username
        string* userArr = userList.getLines("./TEST/login.txt");
        //userList.trim
        cout << " file .txt exists!!" << endl;
        // see if the user isin the array
        cout << "insert username "<< endl;
        //userinput take line and store in input
        string input;
        getline(cin , input);
        cout << "searching for "<< input << endl;

        // search the user input in the user list
        int counter =0;
        while(counter < 254){
            cout << "user n " << counter << "  counted" << userArr[counter] << endl;
            
            if( userArr[counter] == ""){
                counter = 255;
            }

             if( userArr[counter] == input){
            // username found
                cout << "!!!! username "<< input << "found !!!" << endl;
                // register username and continue
                name  = userArr[counter];
                found++;
                //exit loop while condition
                counter = 255;
            
            }else{
                //not found 
                //looping in file
                //cout << "122 login.cpp ,,, username "<< userArr[counter]  << " not " << input << endl;
            }
            cout << "login counter" << found << endl;
            counter++;
        }// while
    }
    }//file check

    //if found is 2 then, folder found, file found, user found return input or return null
    if(found != 2){
     // ask if insert the name if yes insert
     int response;
     cout << "Name in file not found, ? (1)add username     (2)exit" << endl;
     cin >> response;

        if(response == 1){
            // add username
            cout << "writingv NEW username ... " << endl;
            //rewrite all usernames in the file polus new 
            //outfile.open("./TEST/login.txt");
            cout << "Enter Username: "; 

            // somehow write the array and add one

            //

            //outfile << data << endl;
            //outfile.close();

            //log in

        }else{
            // dont add username 2) = exit
            name = "NULL";
            cout << response << endl;
        }

    }
    
    return this-> name;
}

