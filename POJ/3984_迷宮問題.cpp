#include <cstdio>
#include <string>
#include <stack>
#include <utility>

using namespace std;

int map[5][5];
bool visited[5][5];
struct Node {
    int x, y;
    int last;
} q[30];
int head = 0, tail = 0;

bool test(int x, int y){
    if(x >= 0 && y >= 0 && x < 5 && y < 5 && map[x][y] == 0 && !visited[x][y])
        return true;

    return false;
}

int main(){
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            scanf("%d", &map[i][j]);

    memset(visited, 0, sizeof(visited));

    visited[0][0] = true;
    q[tail].x = 0;
    q[tail].y = 0;
    q[tail].last = -1;
    tail++;
    while(head != tail){
        Node cur = q[head++];

        if(cur.x == 4 && cur.y == 4){
            stack<Node> ans;
            ans.push(cur);
            
            while(cur.last != -1){
                cur = q[cur.last];
                ans.push(cur);
            }

            while(!ans.empty()){
                printf("(%d, %d)\n", ans.top().x, ans.top().y);
                ans.pop();
            }
        }

        if(test(cur.x+1, cur.y)){
            visited[cur.x+1][cur.y] = true;
            q[tail].x = cur.x+1;
            q[tail].y = cur.y;
            q[tail].last = head-1;
            tail++;
        }
        if(test(cur.x-1, cur.y)){
            visited[cur.x-1][cur.y] = true;
            q[tail].x = cur.x-1;
            q[tail].y = cur.y;
            q[tail].last = head-1;
            tail++;
        }
        if(test(cur.x, cur.y+1)){
            visited[cur.x][cur.y+1] = true;
            q[tail].x = cur.x;
            q[tail].y = cur.y+1;
            q[tail].last = head-1;
            tail++;
        }
        if(test(cur.x, cur.y-1)){
            visited[cur.x][cur.y-1] = true;
            q[tail].x = cur.x;
            q[tail].y = cur.y-1;
            q[tail].last = head-1;
            tail++;
        }
    }

    return 0;
}
