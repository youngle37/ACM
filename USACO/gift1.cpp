/*
ID: Young Le
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
    
int ppl;
char **Name;
int *money;

int find_name(char* name){

    int ans = 0;

    for(int i=0; i<ppl; ++i){
        if(strcmp(Name[i], name) == 0)
            return i; 
    }

    return -1;
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    fin >> ppl;

    char buffer[100];
    int char_len;

    Name = new char*[ppl];
    for(int i=0; i<ppl; ++i){
        buffer[0] = '\0';
        fin >> buffer;
        char_len = strlen(buffer);
        Name[i] = new char[char_len];
        strcpy(Name[i], buffer);
    }

    money = new int[ppl];

    for(int i=0; i<ppl; ++i)
        money[i] = 0;

    char temp[100];
    int target;
    int share_money, share_ppl;
    int each;

    for(int i=0; i<ppl; ++i){
        fin >> temp;

        target = find_name(temp);
        fin >> share_money >> share_ppl;
        if(share_ppl == 0)
            continue;
        each = share_money / share_ppl;
        money[target] -= each * share_ppl;
        for(int j=0; j<share_ppl; ++j){
            fin >> temp;
            target = find_name(temp);
            money[target] += each;
        }
    }

    for(int i=0; i<ppl; ++i){
        fout << Name[i] << " " << money[i] << endl;
    }

    return 0;
}