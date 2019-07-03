#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.x+r.x,l.y+r.y};                                    
}

struct State {
    pair<int,int> pos;
    int step;
};
int N, M;
vector<pair<int,int>> KFC;
vector<int> KFC_Yi, KFC_Me;
string map[205];
int vis[205][205];
pair<int, int> Yi, Me;
pair<int, int> direction[4] = {
    make_pair(0, -1),
    make_pair(0, 1),
    make_pair(1, 0),
    make_pair(-1, 0)
};

bool test(pair<int, int> pos){
    if(pos.x >= 0 && pos.y >= 0 && pos.x < N && pos.y < M && map[pos.x][pos.y] != '#' && !vis[pos.x][pos.y])
        return true;

    return false;
}

void BFS(pair<int,int> pos, bool isMe){
    State s;
    s.pos = pos, s.step = 0;

    memset(vis, 0, sizeof(vis));
    queue<State> q;
    q.push(s);
    while(!q.empty()){
        State cur = q.front();
        q.pop();

        vector<pair<int,int>>::iterator it;
        it = find(KFC.begin(), KFC.end(), cur.pos);
        if(it != KFC.end()){
            if(isMe)
                KFC_Me[distance(KFC.begin(), it)] = cur.step;
            else
                KFC_Yi[distance(KFC.begin(), it)] = cur.step;
        }

        State tmp;
        for(int i=0; i<4; ++i){
            tmp.pos = cur.pos + direction[i];
            tmp.step = cur.step + 1;
            if(test(tmp.pos)){
                vis[tmp.pos.x][tmp.pos.y] = 1;
                q.push(tmp);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    while(cin >> N >> M){
        cin.ignore();

        KFC.clear();
        for(int i=0; i<N; ++i){
            getline(cin, map[i], '\n');
            for(int j=0; j<M; ++j){
                if(map[i][j] == '@')
                    KFC.push_back(make_pair(i, j));
                else if(map[i][j] == 'Y')
                    Yi = make_pair(i, j);
                else if(map[i][j] == 'M')
                    Me = make_pair(i, j);
            }
        }

        KFC_Yi.resize(KFC.size(), 0x3fffffff);
        KFC_Me.resize(KFC.size(), 0x3fffffff);

        BFS(Yi, 0);
        BFS(Me, 1);

        int ans = 1<<30;
        int len = KFC.size();
        for(int i=0; i<len; i++){
            ans = min(ans, KFC_Yi[i]+KFC_Me[i]);
        }

        cout << ans*11 << '\n';
    }

    return 0;
}
