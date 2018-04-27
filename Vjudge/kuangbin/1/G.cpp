#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

string S1, S2, desired;

string shuffle(string s1, string s2) {
    string ans = "";

    for(int i = 0; i < s1.size(); ++i) {
        ans.push_back(s1[i]);
        ans.push_back(s2[i]);
    }

    return ans;
}

string getS1(string S) {
    return S.substr(S.size() / 2, S.size() / 2);
}

string getS2(string S) {
    return S.substr(0, S.size() / 2);
}

int cnt() {
    set<string> S;

    string temp;
    string nS1 = S1;
    string nS2 = S2;
    int count = 0;
    while(true) {
        temp = shuffle(nS1, nS2);
        nS1 = getS1(temp);
        nS2 = getS2(temp);

        count++;

        if(temp == desired)
            return count;

        if(S.find(temp) != S.end())
            return -1;
        else
            S.insert(temp);
    }
}

int main() {
    int T;
    cin >> T;

    int C;
    for(int i = 1; i <= T; ++i) {
        cin >> C;

        cin >> S1 >> S2 >> desired;

        reverse(S1.begin(), S1.end());
        reverse(S2.begin(), S2.end());
        reverse(desired.begin(), desired.end());

        cout << i << ' ' << cnt() << '\n';
    }

    return 0;
}
