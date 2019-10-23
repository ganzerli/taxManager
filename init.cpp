#include "init.h"
#include <iostream>
using namespace std;

int Init::menu(){

    cout << "welkom bij belastingrekener, ";
    int num;
    bool pass = false;

    while(!pass){
        cout << " kiezen :1: login :2: other";
        cin >> num;
       // cout << "selected" << num << endl;
        cin.clear();
        cin.ignore(10000, '\n');

                if(num < 3 && num > 0){
                   // cout << "ok kiezing in menu" << endl;
                    pass = true;
                    // confirm number stay between 1 and 2
                }else{
                    cout <<  "kiezing " << num <<" ontstaat noch noit, reinsert" << endl;
                    num = 0;
                    pass = false;
                }
        // choose the way profgram works ftom numnber cheooson
        //check if number is a number and in the menu
    }
    return num;
}

string Init::menuGekozen(int num){
    // array of names numered as the given answer 0 is empty
    string fromMenu[3] = {"ERRPR  ERROR  ERROR Init class 36", "login", "other"};
    return fromMenu[num];
}

//
//compile with
//
// g++ -c init.cpp -o init.o
// g++ -c main.cpp -o main.o
// g++ init.o main.o -o main
//
//