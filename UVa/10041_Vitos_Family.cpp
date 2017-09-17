#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);
    while(t--) {
        int r;
        scanf("%d", &r);

        vector<int> s;
        s.resize(r);

        int temp;
        for(int i = 0; i < r; ++i) {
            scanf("%d", &temp);
            s[i] = temp;
        }

        sort(s.begin(), s.end());

        int pos = r / 2;

        int ans = 0;
        for(int i = 0; i < r; ++i) {
            ans += abs(s[i] - s[pos]);
        }

        printf("%d\n", ans);

    }

    return 0;
}
