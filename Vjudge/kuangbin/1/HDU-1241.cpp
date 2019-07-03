#include <iostream>
#include <string>

using namespace std;

int m, n;
string map[100];
bool visited[100][100];

bool test(int i, int j){
    if(i >= 0 && j >= 0 && i < m && j < n && map[i][j] == '@' && !visited[i][j])
        return true;

    return false;
}

void dfs(int i, int j){
    visited[i][j] = true;

    if(test(i-1, j-1))
        dfs(i-1, j-1);
    if(test(i-1, j))
        dfs(i-1, j);
    if(test(i-1, j+1))
        dfs(i-1, j+1);
    if(test(i, j-1))
        dfs(i, j-1);
    if(test(i, j+1))
        dfs(i, j+1);
    if(test(i+1, j-1))
        dfs(i+1, j-1);
    if(test(i+1, j))
        dfs(i+1, j);
    if(test(i+1, j+1))
        dfs(i+1, j+1);
}

int main(){
    ios::sync_with_stdio(false);

    while(cin >> m >> n && m){
        cin.ignore();
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<m; i++)
            getline(cin, map[i], '\n');

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == '@' && !visited[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
