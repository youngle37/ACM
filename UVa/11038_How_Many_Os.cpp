#include <cstdio>

long long int sum0(long long int val){
    long long int sum = 0;
    long long int left = val;
    long long int count = 1;

    while(left >= 10){
        long long int digit = left % 10;
        left /= 10;

        if(digit){
            sum += left*count;
        } else {
            sum += (left-1)*count + val%count + 1;
        }

        count *= 10;
    }

    return sum;
}

int main(){
    long long int a,b;
    while(scanf("%lld%lld", &a, &b) == 2 && a != -1){
        if(a == 0)
            printf("%lld\n", sum0(b) - sum0(a-1) + 1);
        else
            printf("%lld\n", sum0(b) - sum0(a-1));
    }

    return 0;
}
