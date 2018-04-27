#include <cstdio>
#include <set>
#include <math.h>

using namespace std;

bool Happy(int n){
    set<int> S;
    S.insert(n);

    int sum;

    while(n != 1){
        sum = 0;
        while(n != 0){
            sum += pow(n%10, 2);
            n /= 10;
        }

        if(S.find(sum) != S.end())
            return false;

        S.insert(sum);
        n = sum;
    }

    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;++i){
        int n;
        scanf("%d", &n);

        if(Happy(n))
            printf("Case #%d: %d is a Happy number.\n", i, n);
        else
            printf("Case #%d: %d is an Unhappy number.\n", i, n);
    }
    return 0;
}
