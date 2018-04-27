/*
ID: youngle37
PROG: buylow
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>

#define Inf 0x3fffffff

using namespace std;

int N;
int num[5010];
int opt[5010];
int Perm[5010];

int main(){
    //ifstream cin ("buylow.in");
    //ofstream cout ("buylow.out");
    cin >> N;



    for(int i=1;i<=N;++i){
        cin >> num[i];
        opt[i] = 1;
        Perm[i] = 1;
    }

    num[0] = Inf;
    num[N+1] = Inf * -1;
    for(int i=2;i<=N+1;++i){
        vector<bool> visit(5010, 0);
        for(int j=i-1;j>0;--j){
            if(num[j] > num[i] && opt[j]+1 >= opt[i]){
                if(opt[j]+1 > opt[i]){
                    opt[i] = opt[j]+1;
                    Perm[i] = Perm[j];
                }else if(!visit[num[j]]){
                    Perm[i] += Perm[j];
                }

                visit[num[j]] = true;
            }
        }
    }

    cout << opt[N+1] - 1 << ' ' << Perm[N+1] << '\n';

    return 0;
}
