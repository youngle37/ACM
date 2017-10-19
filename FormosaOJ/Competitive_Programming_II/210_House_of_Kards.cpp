#include <iostream>
#include <queue>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    vector<vector<bool>> table;
    table.resize(1001);
    for(int i = 0; i < 1001; ++i)
        table[i].resize(1001);

    vector<int> outdegree;
    outdegree.resize(1001);

    queue<int> q;
    vector<bool> seen(1001);

    int T;
    cin >> T;
    while(T--) {
        for(int i=0;i<1001;++i)
            fill(table[i].begin(), table[i].end(), 0);
        fill(outdegree.begin(), outdegree.end(), 0);
        fill(seen.begin(), seen.end(), false);

        int n;
        cin >> n;
        int temp;
        int maxOut = 0;
        int maxValue = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> temp;
                table[i][j] = temp == 1 ? 1 : 0;
                outdegree[i] += temp == 1 ? 1 : 0;
            }
            if(outdegree[i] > maxValue){
                maxValue = outdegree[i];
                maxOut = i;
            }
        }

        q.push(maxOut);
        int count = 0;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(seen[temp])
                continue;
            ++count;
            seen[temp] = true;
            for(int i=0;i<n;++i){
                if(!table[i][temp])
                    continue;
                q.push(i);
            }
        }

        cout << count << '\n';
    }

    return 0;
}
