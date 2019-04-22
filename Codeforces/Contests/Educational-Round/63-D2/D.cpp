#include <cstdio>

#define max(a,b) ((a<b)?b:a)

long long a[300010];
long long mx[300010];   // best sum from rear

int main(){
    int n, x;
    scanf("%d%d", &n, &x);

    long long sum = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
        sum += a[i];
        if(sum < 0) sum = 0;
        ans = max(ans, sum);
    }

    sum = 0;

    for(int i=n-1; i>=0; i--){
        sum += a[i];
        if(sum < 0) sum = 0;
        mx[i] = max(sum, mx[i+1]);
    }

    if(x > 0){
        printf("%lld\n", max(x*ans, ans));
        return 0;
    }

    long long total = 0;
    sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum < 0) sum = 0;
        // if (sum > total+a[i]*x), then it means no need to multiply, just keeping adding.
        // if (sum < total+a[i]*x), then it means a[i] < 0 so start trying multiply by x
        //      and if (sum > total+a[i]*x) again, then just back to pure prefix sum (reset subarray)
        // SO FUCKING GENIUS
        total = max(sum, total+a[i]*x);
        ans = max(ans, total+mx[i+1]);
    }

    printf("%lld\n", ans);

    return 0;
}
