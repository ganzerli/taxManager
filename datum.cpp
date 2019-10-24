#include "datum.h"
#include<string>
#include<iostream>


using namespace std;

int Datum::compareDatum(string datumEarlier , string datumLater){
    int result = 0;
    // return 0 if earlyer or 1 if later , return 2 if same
    return result;
}

int Datum::formatDatum(string sdatum){
    int datum =0;
    string convertedDatum; 
    int increment = 0;
    // load year dd-mm-yyyy
    for(int i = 6 ; i < 10 ; i++){
        convertedDatum += sdatum[i];
    }
    for(int i = 3 ; i < 5 ; i++){
        convertedDatum += sdatum[i];
    }
    for(int i = 0 ; i < 2 ; i++){
        convertedDatum += sdatum[i];
    }

    //cout << "turned datum" << convertedDatum << endl;
    datum = std::stoi(convertedDatum);
    //cout << "integer datum" << datum << endl;

    return datum;
}

int Datum::ifDatum(string datum){
    int result = 0;
    string tempString ="";
    string day = "";
    string month ="";
    string year = "";
    // if 10 char
    //CRITERIA 1

    if(datum.length() == 10){
       // cout << "string 10 chars" << endl;
        //CRITERIA 2
        // format dd-mm-yyyy

        for(int i = 0 ; i < 2 ; i++){
            day += datum[i];
        }
        // month
        for(int i = 3 ; i < 5 ; i++){
            month += datum[i];
        }
        // year
        for(int i = 6 ; i < 10 ; i++){
            year += datum[i];
        }

        //cout << setDatum[0] << " " << setDatum[1]<< " " << setDatum[2] << endl; 
        if(stoi(day) < 32){
            //cout << "day is less then 332!!" << endl;
            if(stoi(month) < 13){
            //cout << "month is less then 12!!" << endl;
                if(stoi(year) < 2200){
                    //cout << "year is less then 332!!" << endl;
                    result = 1;
                }
            }
        }
    }
    
    // check if the numbers are in a datum available
    // dateDigits 0 to int + 1 toint
      
    return result;
}