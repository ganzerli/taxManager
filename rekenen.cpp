#include"rekenen.h"
#include <iostream>
#include <vector>
// check if digit
#include <ctype.h>

using namespace std;
//has bill of

int Rekenen::getDateMenu(){
   int result = 0;
    // ask user datum or always 
    int input;
    cin.clear();
    cout << "search for always or datum span: 1) ALWAYS  2) DATUM SPAN" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    //cout << "number selected  " << input << endl;

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


float Rekenen::ifBill(string dayBillRecord){
    // returns amount of bill
    float result = 0.00;
    string tempString = "0";
    //search in the string if there is a number
    for(char c : dayBillRecord){
        if(isdigit(c) || c=='.') {
            tempString += c;
        }
    }
    // casting int the string of number found
    result = stof(tempString);

return result;
}


int Rekenen::printBill(vector<vector<string>> daysBill){
    vector<string>dayVect;
    float resultBills=0;
    float resultExpenses=0;
    float amountBill=0;
    float amountExpenses=0;

    float  BTWHIGH;
    float  BTWLOW;

          // having the dates with bill in vector
        for(vector<vector<string>>::iterator i = daysBill.begin(); i != daysBill.end(); ++i){
            // @ OVERWRITE dayVect vector<string>
            dayVect =  *i;
            amountBill = ifBill(dayVect[1]);
            amountExpenses = ifBill(dayVect[3]);
           // cout << dayVect[0] << "has bill of " << amountBill << "  and expenses of " << amountExpenses << endl;
            resultBills+=amountBill;
            resultExpenses+=amountExpenses;
        }
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@"<< endl;
        cout << "total amount of bills" << resultBills << endl;
        cout << "total amount of expenses" << resultExpenses << endl;
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        // ask user quantity of btw
        cout << "ENTER HIGHER BTW AMOUNT" << endl;
        BTWHIGH = inputBtw();

        cout << "ENTER LOWER BTW AMOUNT" << endl;
        BTWLOW = inputBtw(); 

        cout <<"btw =>"<< (resultBills*BTWHIGH)/ 100 << endl;
        cout <<"btw train =>"<< (resultExpenses*BTWLOW)/ 100 << endl;

        cout << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        cout << "MINISTERO MASSIMO GANZERLI" << endl;
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    
        cout << "PAGA ";
        cout << ( (resultBills*BTWHIGH)/ 100) - ( (resultExpenses* BTWLOW)/ 100) << endl;
    
    return 1;
};


float Rekenen::inputBtw(){
    float result = 0.00;
    cin.clear();
    cout << "ENTER BTW AMOUNT |FORMAT 0.00| " << endl;
    cin >> result;
    cin.clear();
    cin.ignore(10000, '\n');
    return result;
}
 

 