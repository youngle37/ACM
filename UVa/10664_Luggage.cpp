#include <bits/stdc++.h>

using namespace std;

int dp[4010];

int main(){
    int T;
    scanf("%d\n", &T);
    while(T--){
        stringstream ss;
        char s[100];
        fgets(s, 100, stdin);
        ss.clear();
        ss.str(s);

        int a[40];
        memset(a, 0, sizeof(a));
        int count = 0;
        int sum = 0;
        while(true){
            ss >> a[count];
            sum += a[count];
            if(ss.fail())
                break;
            count++;
        }

        if(sum % 2){
            printf("NO\n");
            continue;
        }

        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        for(int i=0;i<count;++i){
            for(int j=4000; j>=a[i]; --j){
                if(dp[j-a[i]])
                    dp[j] = 1;
            }
        }

        if(dp[sum/2])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;

}
