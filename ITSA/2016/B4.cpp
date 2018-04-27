#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);

        int temp;
        int temp_sum = 0;
        int ans = 0;
        for(int i=0;i<n;++i){
            scanf("%d", &temp);

            ans += temp_sum + temp/2;

            temp_sum += temp;
        }

        printf("%d\n", ans);

    }

    return 0;
}
