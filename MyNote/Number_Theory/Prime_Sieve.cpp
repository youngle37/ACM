/*
 * 篩法
 * bool 顛倒，節省初始化時間
 * 用 k 取代跳動較大的 j ，減少cache miss
 */

#include <iostream>
#include <vector>
#include <math.h> /* sqrt() */

using namespace std;

#define N 20000000

vector<bool> prime(N, false);

void eratosthenes(){
    int sqrt_N = sqrt(N);
    prime[0] = prime[1] = true;
    for(int i=2; i<=sqrt_N; ++i)
        if(!prime[i])
            for(int k=(N-1)/i, j=i*k; k>=i; k--, j-=i)
                if(!prime[k])
                    prime[j] = true;
}

int main(){
    eratosthenes();

    return 0;
}
