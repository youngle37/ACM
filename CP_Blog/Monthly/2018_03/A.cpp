#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int p,q;
        scanf("%d%d", &p, &q);

        printf("%.0f\n", floor(p*1.0/q - 1e-3));
    }

    return 0;
}
