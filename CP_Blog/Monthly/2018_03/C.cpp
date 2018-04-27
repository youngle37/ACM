#include <cstdio>
#include <vector>

using namespace std;

vector<vector<bool>> connect;
vector<vector<int>> E;
int n, m;

bool Check(int Other){
    vector<int> P(n, -1);

    P[0] = 0;
    P[n/2] = Other;
    
    vector<bool> visit(n, false);
    visit[0] = true;
    visit[Other] = true;

    int count = 2;

    int x = 0, y = Other;
    for(int i=0;i<3&&count!=4;++i){
        for(int j=0;j<3;++j){
            int A = E[x][i];
            int B = E[y][j];
            if(connect[A][B] && A != y && B != x){
                visit[A] = visit[B] = true;
                count = 4;
                P[1] = A; P[1+n/2] = B;
                break;
            }
        }
    }

    if(count != 4)
        return false;

    while(count < n){
        int x = -1;
        for(int i=0;i<3;++i)
            if(!visit[E[P[count/2-1]][i]])
                x = E[P[count/2-1]][i];

        int y = -1;
        for(int i=0;i<3;++i)
            if(!visit[E[P[count/2-1+n/2]][i]])
                y = E[P[count/2-1+n/2]][i];

        if(x == y || x == -1 || y == -1 || !connect[x][y])
            return false;

        count += 2;
        P[count/2-1] = x;
        P[count/2-1+n/2] = y;
        visit[x] = visit[y] = true;
    }

    if(!connect[P[0]][P[n/2-1]] || !connect[P[n/2]][P[n-1]])
        return false;

    printf("%d", P[0]);
    for(int i=1;i<n;i++)
        printf(" %d", P[i]);
    printf("\n");

    return true;
}

void sol(){
    scanf("%d%d", &n, &m);

    for(int i=0;i<E.size();++i)
        E[i].clear();
    for(int i=0;i<connect.size();++i)
        connect[i].clear();

    E.resize(n, vector<int>());
    connect.resize(n, vector<bool>(n, false));

    int x, y;
    for(int i=0;i<m;++i){
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
        connect[x][y] = connect[y][x] = true;
    }

    for(int i=0;i<n;++i){
        if(E[i].size() != 3){
            printf("-1\n");
            return;
        }
    }

    for(int i=0;i<3;++i)
        if(Check(E[0][i])) return;
    printf("-1\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        sol();
    }

    return 0;
}
