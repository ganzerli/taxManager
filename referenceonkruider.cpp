#include "referenceonkruider.h"
#include "filetoarr.h"
#include <vector>
#include <iostream>
using namespace std;

//
//
// cout << "search data from >> 1)datum  2)bill  3)notes  4)expenses  5)other" << endl;
//
//

vector<string> Referenceonkruider::onkruidReference(string path){
    vector<string> oncruiding;
    Filetoarr filArr;
    oncruiding = filArr.getLinesV(path);
    // open file 
    //get lines
    //fill vector
    return oncruiding;
}