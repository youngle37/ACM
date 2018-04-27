#include <iostream>
#include <vector>

using namespace std;

struct block{
    int l;
    int m;
    int s;
};

int main(){
    int T = 0;
    int n;
    vector<block> B(35);
    int x,y,z;
    block temp;
    while(cin >> n && n){
        ++T;

        for(int i=0;i<n;++i){
            cin >> x >> y >> z;
            temp.l = max(x,max(y,z));
            temp.s = min(x,min(y,z));
            temp.m = x+y+z-temp.l-temp.s;
        }

        
    }

    return 0;
}
