#include"datafile.h"
#include"datum.h"

#include"filetoarr.h"

#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

    vector<string> Datafile::userInput(){
        // array of inputs to array of answers
        Datum datum;
        // !! TO DO !! get arr from file to let define user the whole capacity of the database .. mar later..
        // probleme > user curva input inzetten , nit te uitkrijgen op gezoegte gewijzigte tabele.
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
            cout << "DATA for"<< datainput[i] <<" : "<< stringInput <<"  "<< i << " of "<< arrSize << endl;
        }
        datum.ifDatum(userInput[0]);
        
        
    //cout << "datafile: all data inserted"<< endl;
    // check data input 1 if is datum , if not repeat insert datum or reinsert one data
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
        //cout << "i = " << i <<endl;  
         dataLine = dataLine + i + "<//>";
    } 
    // take last chars from string
    dataLine = dataLine.substr(0, dataLine.size()-4);
    dataLine = dataLine + "<=/";
    //cout << dataLine << endl;
    return dataLine;
}


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

    for(string i : fileLines){
      //  cout << "i = add record" << i << endl;
        data = i + data ;
    }
    
    data = data + newInput;
    cout << data << endl;
   // cout <<"data printed" << endl;
    // crate instance to write to the file
    ofstream outfile;
    outfile.open(filepath);
    outfile << data << endl;
    return inserted;
}

int Datafile::replaceFile(string filepath , string newInput){
    int replaced = 0;
    ofstream outfile;
    outfile.open(filepath);
    outfile << newInput << endl;
    cout << "written " << newInput << " in " << filepath << endl; 
    replaced += 1;
    return replaced;
}