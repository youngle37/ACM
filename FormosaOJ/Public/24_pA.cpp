#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){ _
    vector<int> v;
    queue<int> qu;
    int input;

    while(cin >> input){
        if(!input)
            break;
        else if(input > 0)
            v.push_back(input);
        else{
            if(!v.empty())
                qu.push(input);
        }

        while(!qu.empty() && !v.empty()){
            sort(v.begin(), v.end());

            if(qu.front() == -1){
                cout << v.front() << ' ';
                v.erase(v.begin());
            }
            else{
                cout << v.back() << ' ';
                v.pop_back();
            }

            qu.pop();
        }
    }

    cout << '\n';

    return 0;
}
