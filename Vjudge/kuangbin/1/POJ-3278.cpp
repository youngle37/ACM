#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit(100005);

int main(){
    int n,k;
    while(cin >> n >> k){
        fill(visit.begin(), visit.end(), 0);
        queue<int> q;
        q.push(n);

        while(!q.empty()){
            int now = q.front();
            q.pop();

            if(now == k)
                break;

            if(now > 0 && !visit[now-1]){
                q.push(now-1);
                visit[now-1] = visit[now] + 1;
            }

            if(now < k && !visit[now+1]){
                q.push(now+1);
                visit[now+1] = visit[now] + 1;
            }

            if(2*now < 100001 && !visit[2*now]){
                q.push(2*now);
                visit[2*now] = visit[now] +1;
            }
        }

        cout << visit[k] << '\n';
    }

    return 0;
}
