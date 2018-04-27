#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<int> cost;
        int temp;
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            cost.push_back(temp);
        }

        sort(cost.begin(), cost.end());

        int sum = 0;
        for(int i = 0; i < m; ++i) {
            if(cost[i] < 0)
                sum += cost[i];
            else
                break;
        }

        sum *= -1;

        cout << sum << '\n';
    }

    return 0;
}
