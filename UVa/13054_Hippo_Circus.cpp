#include <iostream>
#include <queue>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    int C;
    cin >> C;
    for(int c = 1; c <= C; ++c) {
        int N, H, T_a, T_d;
        int ans = 0;

        cin >> N >> H >> T_a >> T_d;

        if(T_a * 2 <= T_d) {
            for(int i = 0; i < N; ++i)
                cin >> ans;
            cout << "Case " << c << ": " << T_a * N << '\n';
            continue;
        }

        vector<int> lower;
        vector<int> higher;
        lower.reserve(N);
        higher.reserve(N);
        int criteria = H % 2 ? H / 2 : H / 2 - 1;
        int input;
        for(int i = 0; i < N; ++i) {
            cin >> input;
            if(input <= criteria)
                lower.push_back(input);
            else
                higher.push_back(input);
        }

        priority_queue<int> max_heap(higher.begin(), higher.end());
        priority_queue<int, vector<int>, greater<int>> min_heap(lower.begin(), lower.end());

        while(!max_heap.empty() && !min_heap.empty()) {
            if(max_heap.top() + min_heap.top() < H) {
                ans += T_d;
                max_heap.pop();
                min_heap.pop();
            } else {
                ans += T_a;
                max_heap.pop();
            }
        }

        ans += T_a * max_heap.size();

        int remainder = min_heap.size();
        if(remainder % 2) {
            ans += T_a;
            ans += T_d * (remainder / 2);
        } else
            ans += T_d * remainder / 2;

        cout << "Case " << c << ": " << ans << '\n';
    }

    return 0;
}
