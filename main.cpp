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
    bool pass;
    // entering menu
    // class init start the program and has menuhandler
    int numberSelected = init.menu();
    while ( numberSelected == 0 ){
        numberSelected = init.menu();
    }
    string text = init.menuGekozen(numberSelected);
    // when number selected is in the menu..

    //have a menuhandler to get the write name program class Login
    login.checkUsername(); 
    cout << "check main , logged in as .. " << login.getName() << endl;
    // if user registered login ok and ask options write read
    // switch handler 
    while(!pass){
        if ( login.getName() != "NULL" ){
            // if not created init folder
            // ask what to do
        
            cout << " welcome  " << login.getName() << " choose an option for the data management" << endl;
            cout << "1 >> write to file " << endl;
            cout << "2 >> find  " << endl;
            cout << "3 >> rekenen  " << endl;
            cout << "4 >> change " << endl;
            int input;
            cin >> input;
            cin.clear();
            cin.ignore(10000, '\n');

            // prepare folders for logged in user if not existing
            crmenu.init(login.getName());
            // for input check if number and in menu 
            crmenu.switchHandler(input, login.getName());
        }else{
            cout << "insert name again" << endl;
            login.checkUsername();
            cout << "NO RECORDS FOUND.. WRITE DATA REQUIRED";
            cout <<"press any key to write to file" << endl;
            crmenu.init(login.getName());
            // for input check if number and in menu 
            crmenu.switchHandler(1, login.getName());
        }
        cout << ".. continue or exit , select : " << endl;
        cout << "   1) Continue logged in" << endl;
        cout << "   2) Exit" << endl;
        
        
        string theString;
        getline(cin, theString);
        cin.clear();
        // cin.ignore(10000, '\n');
        cout << "written :" << theString << endl;
        if(theString == "1"){
            pass = false;
        }else if(theString == "2"){
            pass = true;
            cout << "Exit program ..." << endl;
        }
    }

    // save to then writre in the doc

    return 1;
}