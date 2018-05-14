#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Cli{
    int start;
    int end;
    int val;
    Cli(){}
    Cli(int s, int e, int w):start(s),end(e),val(w){}
};

Cli cli[110];
int N;

bool myComp(Cli a, Cli b){
    return a.end < b.end;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);

        int s,e,w;
        for(int i=1;i<=N;++i){
            scanf("%d %d %d", &s, &e, &w);
            cli[i] = Cli(s,e,w);
        }

    }

    return 0;
}
