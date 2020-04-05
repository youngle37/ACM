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

int N;
int k, r, c;
int mat[101][101];
bool vis[101];

void solve() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> mat[i][j];
        }
    }

    k = r = c = 0;

    // k
    for(int i=0; i<N; ++i)
        k += mat[i][i];

    // r
    for(int i=0; i<N; ++i) {
        memset(vis, 0, sizeof(vis));
        for(int j=0; j<N; ++j) {
            if(vis[mat[i][j]]) {
                ++r;
                break;
            }
            vis[mat[i][j]] = 1;
        }
    }

    // c
    for(int j=0; j<N; ++j) {
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<N; ++i) {
            if(vis[mat[i][j]]) {
                ++c;
                break;
            }
            vis[mat[i][j]] = 1;
        }
    }

}

int main(){
    int x;
    cin >> x;
    for(int i=1; i<=x; ++i) {
        cin >> N;
        solve();
        cout << "Case #" << i << ": " << k << " " << r << " " << c << '\n';
    }

    return 0;
}
