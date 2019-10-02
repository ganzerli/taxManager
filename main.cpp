#include"init.h"
#include"login.h"
#include"Filetoarr.h"
#include"Crudmenu.h"

#include<iostream>

using namespace std;

// insert in the day, and possibility to modify and add to the day bill.
// sign costs of living , trasport per mont, to find unuseful expenses and get tipps to cut
// print values together at choosen option. day by day per thing

int main (){
    //init classes 
    Init init;
    Login login;
    Filetoarr arrfile;
    Crudmenu crmenu;
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
    login.checkUsername(); 

    cout << "logged in as main " << login.getName() << endl;
    // if user registered login ok and ask options write read
    // switch handler 
    if ( login.getName() != "NULL" ){
        // if not created init folder
        // ask what to do
      
        cout << " welcome  " << login.getName() << " choose an option for the data management" << endl;
        cout << "1 >> write to file " << endl;
        cout << "2 >> find  " << endl;
        cout << "3 >> rekenen  " << endl;
        
        int input;
        cin >> input;
        cin.clear();
        cin.ignore(10000, '\n');

        // prepare folders for logged in user is not existing
        crmenu.init(login.getName());
        crmenu.switchHandler(input, login.getName());
    }
    // class write menu , init folder with username


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