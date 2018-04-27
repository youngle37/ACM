#include <iostream>
#include <string>
#include <vector>

#define pii pair<int,int>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;

    vector<string> S(n);
    for(int i=0;i<n;++i)
        cin >> S[i];

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string query;
    for(int i=0;i<q;++i){
        getline(cin,query);
        cout << query << '\n';
    }

    return 0;
}
