#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> map(8);
bool placed[10];
int n,k;
int ans;
int cnt;

void DFS(int cur){
    if(cnt == k){
        ans++;
        return;
    }

    if(cur >= n)
        return;

    for(int i=0;i<n;++i){
        if(map[cur][i] == '#' && !placed[i]){
            placed[i] = true;
            cnt++;
            DFS(cur+1);
            placed[i] = false;
            cnt--;
        }
    }

    DFS(cur+1);
}

int main() {
    while(cin >> n >> k && (~n || ~k)) {
        cin.ignore(255, '\n');

        fill(placed, placed+n, false);
        for(int i=0;i<n;++i)
            getline(cin, map[i]);

        ans = cnt = 0;
        DFS(0);
        cout << ans << '\n';
    }

    return 0;
}
