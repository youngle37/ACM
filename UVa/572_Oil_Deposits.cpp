#include <iostream>
#include <vector>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int ans;
int m, n;

void dfs(char (&map)[100][100], vector<vector<int>> &visited, int i, int j){
    if(map[i][j] != '@')
        return;

    if(visited[i][j])
        return;

    visited[i][j] = 1;

    if(i)
        dfs(map, visited, i-1, j);
    if(j)
        dfs(map, visited, i, j-1);
    if(i < m - 1)
        dfs(map, visited, i+1, j);
    if(j < n - 1)
        dfs(map, visited, i, j+1);
    
    if(i && j)
        dfs(map, visited, i-1, j-1);
    if(i && j < n - 1)
        dfs(map, visited, i-1, j+1);
    if(j && i < m - 1)
        dfs(map, visited, i+1, j-1);
    if(i < m - 1 && j < n - 1)
        dfs(map, visited, i+1, j+1);
}

int main(){
    _
    char map[100][100];
    vector<vector<int>> visited(100, vector<int>(100));

    string temp;
    while(cin >> m >> n && m != 0){
        for(auto &v : visited)
            fill(v.begin(), v.end(), -1);

        for(int i=0;i<m;++i){
            cin >> map[i];
            for(int j=0;j<n;++j){
                if(map[i][j] == '@')
                    visited[i][j] = 0;
            }
        }

        ans = 0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(map[i][j] == '@' && !visited[i][j]){
                    dfs(map, visited, i, j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';

    }

    return 0;
}
