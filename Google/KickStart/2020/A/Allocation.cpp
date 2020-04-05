#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int a[100005];
int N;

int solve() {
    int b = 0;
    int ans = 0;
    cin >> N >> b;

    for(int i=0; i<N; ++i)
        cin >> a[i];

    sort(a, a+N);

    for(int i=0; i<N; ++i) {
        if(b >= a[i]) {
            b -= a[i];
            ++ans;
        }
    }

    return ans;
}

int main(){
    int t = 0, T;
    cin >> T;
    while(t++ < T)
        cout << "Case #" << t << ": " << solve() << "\n";

    return 0;
}
