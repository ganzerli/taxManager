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