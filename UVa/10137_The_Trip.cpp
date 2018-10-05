#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    int pay[1010];
    while(scanf("%d", &n) && n){
        int t1, t2;
        int ans = 0, avg = 0;
        int more;
        for(int i=0;i<n;i++){
            scanf("%d.%d", &t1, &t2);
            pay[i] = t1 * 100 + t2;
            avg += pay[i];
        }
        more = avg % n;
        avg /= n;
        sort(pay, pay+n, cmp);
        for(int i=0; i<more; i++){
            ans += abs(pay[i] - avg - 1);
        }
        for(int i=more; i<n; i++){
            ans += abs(pay[i] - avg);
        }
        printf("$%.2f\n", ans/200.0);
    }

    return 0;
}
