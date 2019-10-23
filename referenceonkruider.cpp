#include "referenceonkruider.h"
#include "filetoarr.h"
#include <vector>
#include <iostream>
using namespace std;

vector<string> Referenceonkruider::onkruidReference(string path){
    vector<string> oncruiding;
    Filetoarr filArr;
    cout << "oncruiding de Reference" << endl;
    oncruiding = filArr.getLinesV(path);
    // open file 
    //get lines
    //fill vector
    return oncruiding;
}