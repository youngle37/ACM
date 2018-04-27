/*
 *
 * 不管 i 是否為質數，都會執行 Note 1 的迴圈
 *
 * 1. 若 i 為質數：
 *      篩出的數都是 N = p1 * p2 (p1 < p2)
 *      這樣的數到 p2 之前是不會篩過的
 *
 * 2. 若 i 為合數：
 *      i = p1 * p2 * p3 ...
 *      在 Note 2 時，當 prime[j] == p1 時，篩除就終止了。
 *      也就是說只能篩掉<=p1的質數*i
 *
 * Ex：
 * 若 i = 2*3*5
 * 此時會篩掉 2*i 不會篩 3*i
 * 若會篩掉 3*i 的話，當 i = 3*3*5 時且要篩 2*i 時就會重複了
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 200;
bool sieve[N];

void init_sieve() {
    vector<int> prime;
    for(int i = 2; i < N; ++i) {
        if(!sieve[i])
            prime.push_back(i);

        // Note 1
        for(int j = 0; i * prime[j] < N; ++j) {
            sieve[i * prime[j]] = true;
            // Note 2
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    init_sieve();

    return 0;
}
