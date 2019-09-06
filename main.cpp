#include"init.h"
#include"login.h"
#include"Filetoarr.h"

#include<iostream>

using namespace std;

int main (){
    //init classes 
    Init init;
    Login login;
    Filetoarr arrfile;
    // entering menu
    // class init start the program and has menuhandler
    int numberSelected = init.menu();
    while ( numberSelected == 0 ){
        numberSelected = init.menu();
    }
    string text = init.menuGekozen(numberSelected);
    // when number selected is in the menu..
    cout << "abc init.menuGekozen says   ////>>>>  " << text << endl;

    //have a menuhandler to get the write name program class Login
    //login.setName("user");
    //text = login.getName();
    //cout << "login.getName says   22222>>>>  " << text << endl;

    login.checkUsername(); // does not return redable text

    text = login.getName();
    cout << "logged in as main " << login.getName();

    arrfile.getLines("./TEST/login.txt");






    ////
    //
    //
    //
    //
    //
    cout << "enter something at your needs :" << endl;
    string theString;
    getline(cin, theString);
    cout << "written :" << theString << endl;

    // save  to then writre in the doc
    

    
    return 1;
}