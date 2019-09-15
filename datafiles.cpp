#include"datafiles.h"

#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

vector<string> Datafiles::getInput(){
    // array of inputs to array of answers
    string datainput[5] = {"enter day", "amount bill", "notes", "expenses", "other"};
    vector<string> userInput;
    for ( int i = 0 ; i < sizeof(datainput); i++){
        cout << datainput[i] <<endl;
    }

    return userInput;
};
