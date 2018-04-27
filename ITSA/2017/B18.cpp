#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int P, Q, R, s1, s2;

int F(int x, int y) {
    return (Q * x + R * (x - y) * (x - y) + y) % P;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> P >> Q >> R >> s1 >> s2;

        set<pii> S;
        S.insert(mp(s1, s2));

        vector<int> val;
        val.push_back(s1);
        val.push_back(s2);

        pii temp_pair;
        int temp;
        int i = 2;
        do {
            temp = F(val[i-2], val[i-1]);
            val.push_back(temp);
            temp_pair = mp(val[i-1], temp);

            if(S.find(temp_pair) != S.end())
                break;

            S.insert(temp_pair);
            i++;
        } while(1);

        cout << S.size() << '\n';
    }

    return 0;
}
