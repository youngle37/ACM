#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

#define MAXN 30

using namespace std;

vector<int> node;
vector<int> G[MAXN];
bool vis[MAXN];

bool valid(int u) {
    for(int i=0; i<G[u].size(); ++i) {
        if(vis[G[u][i]])
            return false;
    }
    return true;
}

void DFS(string tmp) {
    if(tmp.size() == node.size()) {
        cout << tmp << '\n';
        return;
    }

    for(int i=0; i<node.size(); ++i) {
        if(!vis[node[i]]) {
            vis[node[i]] = true;
            if(valid(node[i]))
                DFS(tmp+(char)(node[i]+'a'));
            vis[node[i]] = false;
        }
    }
}

int main(){
    string line;
    int cas = 0;
    while(getline(cin, line)) {
        if(cas++) cout << '\n';

        node.clear();
        for(int i=0; i<line.size(); ++i) {
            if(line[i] != ' ')
                node.push_back(line[i]-'a');
        }
        sort(node.begin(), node.end());

        getline(cin, line);
        for(int i=0; i<MAXN; ++i) G[i].clear();
        for(int i=0; i<line.size(); i+=4) {
            int u = line[i]-'a';
            int v = line[i+2]-'a';
            G[u].push_back(v);
        }

        memset(vis, 0, sizeof(vis));
        DFS("");
    }

    return 0;
}
