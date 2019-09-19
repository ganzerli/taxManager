#include"datafile.h"

#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

    vector<string> Datafile::userInput(){
        // array of inputs to array of answers
        const int arrSize = 5;
        string datainput[arrSize] = {"enter day", "amount bill", "notes", "expenses", "other"};
        string stringInput;
        vector<string> userInput;
        cout << "PRESS RETOURN TO COFIRM" << endl;

        cin.clear();
        cin.ignore(10000, '\n');

        for ( int i = 0 ; i < arrSize; i++){
            cout << datainput[i] << endl;
            getline(cin, stringInput);
            userInput.push_back(stringInput);
        
            // for input get strigs from user
           // cout << userInput[i] << endl;
           cout << "DATA INSERTED   :"<< stringInput <<"  "<< i << "  "<<arrSize<< endl;
        }
           // cin.clear();
           //cin.ignore(10000, '\n');
    cout << "DATA INSERTED    DATA INSERTED    DATA INSERTED datafile"<< endl;
        return userInput;
    };

