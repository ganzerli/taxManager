#include"search.h"
#include <iostream>
#include <fstream> 
#include <vector>
#include <string>

using namespace std;

vector<string> Search::getFilesFrom(string path){
    vector<string> possibleNames;
    string possibleStringDate;
    const int MONTHSLIMIT = 12;
    const int YEARSENDDATE = 2035;
    const int YEARBEGINDATE = 2019;
    // have a yro time .. of .... ... now..
    // in 100 years all , all , all neighborhoods are dead, thaz why we have a limit of 200, because for us is alwais better that they are dead.. in all cases.. eh..
    for(int i = YEARBEGINDATE; i < YEARSENDDATE; i++){
        for(int j = 1; j <= MONTHSLIMIT; j++){
            cout <<"possible date , and possinble files " << j <<'-' << i << endl; 
            possibleStringDate = j + '-' +  i ;
            possibleNames.push_back(possibleStringDate);
        }
    }
    cout << path << endl;
    const int MONTHSINYEAR = 12;
    // needed .. search in months, of the years, bidimensional loop

    //YeRS.. from the date
    // needed function translating strings to int
    return possibleNames;
}