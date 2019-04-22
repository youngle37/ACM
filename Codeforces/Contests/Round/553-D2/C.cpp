#include <iostream>

#define mod 1000000007

using namespace std;

unsigned long long sum_f(unsigned long long n){
    unsigned long long cur = 1, ret = 0, odd = 1, even = 2;
    bool turn = true;

    while(true){
        if(2*cur-1 > n)
            break;

        if(turn){
            unsigned long long sum = (odd + cur-1) % mod;
            sum = (sum*(cur%mod)) % mod;
            ret = (ret + sum) % mod;
            odd += cur*2;
        } else {
            unsigned long long sum = (even + cur-1) % mod;
            sum = (sum*(cur%mod)) % mod;
            ret = (ret + sum) % mod;
            even += cur*2;
        }

        turn ^= 1;
        cur *= 2;
    }

    unsigned long long remainder = n - (cur-1);
    if(n >= cur){
        if(turn){
            unsigned long long sum = (odd + remainder-1) % mod;
            sum = (sum*(remainder%mod)) % mod;
            ret = (ret + sum) % mod;
        } else {
            unsigned long long sum = (even + remainder-1) % mod;
            sum = (sum*(remainder%mod)) % mod;
            ret = (ret + sum) % mod;
        }
    }

    return ret;
}

int main(){
    unsigned long long l,r;
    cin >> l >> r;

    cout << (sum_f(r) - sum_f(l-1) + mod) % mod << '\n';

    return 0;
}
