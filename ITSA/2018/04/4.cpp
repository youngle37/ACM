#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> T;
vector<bool> visit(100);
int sum;
bool found;
int now;
int n;

bool myComp(const int i, const int j){
    return j > i;
}

bool dfs(int cur, int acc){
    if(now == 3)
        return true;

    if(acc == sum / 4){
        now++;
        if(dfs(0, 0))
            return true;
    }

    for(int i=cur; i < n;++i){
        if(!visit[i] && T[i]+acc <= (sum / 4)){
            visit[i] = true;
            if(dfs(i+1, acc+T[i]))
                return true;
            visit[i] = false;
        }
    }

    return false;
}
        

int main(){
    while(scanf("%d", &n) != EOF){
        T.resize(n);

        if(n < 4){
            printf("no\n");
            continue;
        }

        sum = 0;

        for(int i=0;i<n;++i){
            scanf("%d", &T[i]);
            sum += T[i];
        }

        if(sum % 4 != 0){
            printf("no\n");
            continue;
        }

        bool fail = false;
        for(int i=0;i<n;++i){
            if(T[i] > sum / 4){
                fail = true;
                break;
            }
        }

        if(fail){
            printf("no\n");
            continue;
        }

        sort(T.begin(), T.end(), myComp);

        found = false;
        now = 0;
        fill(visit.begin(), visit.end(), false);

        if(dfs(0, 0))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
