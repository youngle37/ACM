#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(vector<int> &nxt, string &P) {
    int len = P.length();
    nxt = vector<int>(len);
    int i = 0, j = -1;
    nxt[0] = -1;

    while(i < len) {
        while(j > -1 && P[i] != P[j])
            j = nxt[j];
        ++i;
        ++j;
        if(P[i] == P[j])
            nxt[i] = nxt[j];
        else
            nxt[i] = j;
    }
}

void kmp(string &T, string &P) {
    vector<int> nxt;
    getNext(nxt, P);

    cout << "nxt: \n";
    for(int v : nxt){
        cout << v << ' ';
    }
    cout << '\n';

    int len_T = T.length();
    int len_P = P.length();

    if(len_P > len_T) return;

    int i = 0, j = 0;
    while(j < len_T){
        if(i == -1 || T[j] == P[i]){
            i++;
            j++;
            if(i >= len_P){
                cout << j - i << '\n';
                i = nxt[i];
            }
        } else{
            i = nxt[i];
        }
    }
}

int main() {
    string T = "a";
    string P = "ababbabab";

    kmp(T, P);

    return 0;
}
