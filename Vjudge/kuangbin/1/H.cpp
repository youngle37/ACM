#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

const int maxn = 200;

bool vis[maxn][maxn];
int A, B, C;
int step;

struct Status{
    int k1,k2;
    int op;
    int step;
    int pre;
} q[maxn*maxn];
int id[maxn*maxn];
int lastIndex;

void bfs(){
    Status now, next;

    int head, tail;
    head = tail = 0;

    q[tail].k1 = 0; q[tail].k2 = 0;
    q[tail].op = 0; q[tail].step = 0; q[tail].pre = 0;

    tail++;

    memset(vis, false, sizeof(vis));
    vis[0][0] = true;

    while(head < tail){
        now = q[head];
        head++;

        for(int i=1;i<=6;++i){
            if(i==1){           // Fill(1)
                next.k1 = A;
                next.k2 = now.k2;
            }else if(i==2){     // Fill(2)
                next.k1 = now.k1;
                next.k2 = B;
            }else if(i==3){     // Drop(1)
                next.k1 = 0;
                next.k2 = now.k2;
            }else if(i==4){     // Drop(2)
                next.k1 = now.k1;
                next.k2 = 0;
            }else if(i==5){     // Pour(1,2)
                if(now.k1+now.k2 <= B){
                    next.k1 = 0;
                    next.k2 = now.k1+now.k2;
                }else{
                    next.k1 = now.k1+now.k2-B;
                    next.k2 = B;
                }
            }else{              // Pour(2,1)
                if(now.k1+now.k2 <= A){
                    next.k1 = now.k1+now.k2;
                    next.k2 = 0;
                }else{
                    next.k1 = A;
                    next.k2 = now.k1+now.k2-A;
                }
            }

            next.op = i;
            if(!vis[next.k1][next.k2]){
                vis[next.k1][next.k2] = true;

                next.step = now.step + 1;
                next.pre = head - 1;

                q[tail].k1 = next.k1; q[tail].k2 = next.k2;
                q[tail].op = next.op; q[tail].step = next.step; q[tail].pre = next.pre;

                tail++;

                if(next.k1 == C || next.k2 == C){
                    step = next.step;
                    lastIndex = tail - 1;
                    return;
                }
            }
        }
    }
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    while(scanf("%d %d %d", &A, &B, &C) != EOF){
        if(C % gcd(A,B) != 0){
            printf("impossible\n");
            continue;
        }

        step = 0;

        bfs();

        printf("%d\n", step);

        id[step] = lastIndex;
        for(int i=step-1; i>0;--i){
            id[i] = q[id[i+1]].pre;
        }

        for(int i=1; i<=step;++i){
            if(q[id[i]].op == 1){
                printf("FILL(1)\n");
            }else if(q[id[i]].op == 2){
                printf("FILL(2)\n");
            }else if(q[id[i]].op == 3){
                printf("DROP(1)\n");
            }else if(q[id[i]].op == 4){
                printf("DROP(2)\n");
            }else if(q[id[i]].op == 5){
                printf("POUR(1,2)\n");
            }else{
                printf("POUR(2,1)\n");
            }
        }
    }

    return 0;
}
