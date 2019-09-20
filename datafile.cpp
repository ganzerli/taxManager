#include"datafile.h"
#include"filetoarr.h"

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
           cout << "DATA INSERTED   :"<< stringInput <<"  "<< i << " of "<< arrSize << " info elements" << endl;
        }
    cout << "datafile: all data inserted"<< endl;
        return userInput;
    };

int Datafile::checkFile(string filepath){
    int check = 0;
    //open file
     //check for file
        ifstream ifile;
        ifile.open(filepath); 
        // crate instance to write to the file
        ofstream outfile;
    if(!ifile || ifile.fail()){
        // file not found create file and add a user
        cout << "file does not exist" << endl;
    }else{
        check = 1;
    }
    // close file
    return check;
}

int Datafile::createFile(string filepath , string line){
    int created = 0;
    return created;
};

string Datafile::dataToString(vector<string> userInput){
    string dataLine="/=>";
    // vector to string
    for(string i : userInput){
        cout << "i = " << i <<endl;  
         dataLine = dataLine + i + "<//>";
    } 
    // take last chars from string
    dataLine = dataLine.substr(0, dataLine.size()-4);
    dataLine = dataLine + "<=/";
    cout << dataLine << endl;
    return dataLine;
}

//

int Datafile::addRecord(string filepath , string newInput){
    int inserted = 0;
    Filetoarr getFileInfo;
    string data;
 
    // open file 
    ifstream ifile;
    ifile.open(filepath);

    //file is there, get text
    // retirn one string , rewriting..
    vector<string> fileLines = getFileInfo.fileToVector(filepath);
    //
    // work in progress
    //
    //
    for(string i : fileLines){
        cout << "i = add record" << i << endl;
        data = i + data ;
    }
    data = data + newInput;
    cout << data << endl;
    cout <<"data printed" << endl;
    // crate instance to write to the file
    ofstream outfile;
    outfile.open(filepath);
    outfile << data << endl;
    return inserted;
}