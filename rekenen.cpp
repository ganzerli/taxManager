#include"rekenen.h"
#include <iostream>

using namespace std;

int Rekenen::getDateMenu(){
   int result = 0;
    // ask user datum or always 
    int input;
    cin.clear();
    cout << "search for always or datum span: 1) ALWAYS  2) DATUM SPAN" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "number selected  " << input << endl;

    if(input == 1){
        result = 0;
    }else if(input < 1 || input > 2){
        cout << "in menu datum number "<< input << "not existing" << endl;
    }else if(input == 2 ){
        result = 1;
    }

    // return array with datum begin and end
    // needed datum format and datum check
    return result;
}

string* Rekenen::getDateSpan(){
    // ask day span and insert in array
    static string arr[2];

    cin.clear();
    cout << "insert date beginning search"<< endl;
    cin >> arr[0];
    cout << "insert date ending search"<< endl;
    cin >> arr[1];
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "selected  from  " << arr[0] << "to" << arr[1] << endl;
    
    return arr;
    // check if are datums and which is first which after

}

