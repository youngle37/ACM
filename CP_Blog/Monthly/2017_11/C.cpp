#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    int N, T;
    cin >> N >> T;

    if(N < T) {
        cout << -1;
        return 0;
    }

    if(!T){
        cout << -1;
        return 0;
    }

    for(int i = 1; i < N; ++i)
        cout << i << ' ';
    cout << N << '\n';

    int dis = N - T;
    for(int i = 1; i < T; ++i)
        cout << i + dis << ' ';
    cout << T + dis;

    for(int i = dis; i > 0; --i)
        cout << ' ' << i;

    return 0;
}
