#include <string>
#include <vector>
#include <iostream>

using namespace std;

string str;
vector<int> nex(1000010);

void getnext(int len){      
    int i=0,j=-1;
    nex[0]=-1;
    while(i<len){
        if(j==-1 || str[i]==str[j]){
            i++;j++;
            nex[i]=j;
        }else
            j=nex[j];
    }
}

int main(){
    while(cin >> str){
        fill(nex.begin(), nex.begin()+str.size(), 0);
        getnext(str.size()-1);

        for(int i=0;i<str.size();++i)
            cout << nex[i] << ' ';

        for(int i=0;i<str.size();++i){
            int test = i - nex[i];
            if(i%test || i == test)
                continue;
            cout << test << ' ' << i/test << '\n';
        }
    }

    return 0;
}
