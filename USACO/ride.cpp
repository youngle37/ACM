/*
ID: Young Le
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    if(!fin){
        cout << "WTF" << endl;
        exit(1);
    }

    string input[2];
    int product[2] = {1, 1};
    fin >> input[0] >> input[1];
    
    for(int i = 0 ; i < input[0].length() ; i++){
        product[0] *= (int)input[0].at(i) - 64;
    }


    for(int i = 0 ; i < input[1].length() ; i++){
        product[1] *= (int)input[1].at(i) - 64;
    }

    if(product[0] % 47 == product[1] % 47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
