#include <iostream>
#include <vector>
#include <utility>

#define pii pair<int,int>

using namespace std;

int main() {
    vector<pii> tur(5617);

    system("timeout");
    cout << "??";

    pii temp;
    int i = 0;
    while(cin >> temp.first >> temp.second) {
        temp.second -= temp.first;
        tur[i] = temp;
        ++i;
    }

    
    
    return 0;
}
