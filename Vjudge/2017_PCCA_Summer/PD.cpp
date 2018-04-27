#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char str[101];
    char del[] = "+";
    char *s;
    vector<int> num;
    while(cin.getline(str, sizeof(str))) {
        num.clear();
        s = strtok(str, del);
        while(s != NULL) {
            num.push_back(s[0] - '0');
            s = strtok(NULL, del);
        }

        sort(num.begin(), num.end());

        cout << num[0];
        for(int i = 1; i < num.size(); ++i) {
            cout << '+' << num[i];
        }

        cout << '\n';
    }
}
