#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

struct TIME {
    int id;
    int t;
    bool is_start;
};

int ans;
string ans_str;
int N;

bool comp(TIME a, TIME b) {
    if(a.t != b.t) return a.t < b.t;
    else return !a.is_start;
}

void solve() {
    ans = 0;
    ans_str = "";

    cin >> N;
    vector<TIME> timeline;
    int start, end;
    for(int i=0; i<N; ++i) {
        cin >> start >> end;
        timeline.push_back(TIME{i, start, true});
        timeline.push_back(TIME{i, end, false});
    }

    sort(timeline.begin(), timeline.end(), comp);

    int cnt = 0;
    int J = -1, C = -1;
    for(auto s : timeline) {
        if(s.is_start) {
            ++cnt;
            if(J == -1) {
                ans_str += "J";
                J = s.id;
            } else {
                ans_str += "C";
                C = s.id;
            }
        }
        else {
            --cnt;
            if(J == s.id) J = -1;
            else C = -1;
        }

        ans = max(ans, cnt);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t) {
        solve();

        if(ans > 2) cout << "Case #" << t << ": IMPOSSIBLE\n";
        else cout << "Case #" << t << ": " << ans_str << "\n";
    }

    return 0;
}
