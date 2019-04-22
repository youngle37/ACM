#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3fffffff

const int N = 10010;
vector<bool> sieve(N, false);
int m, p;

void init_sieve() {
    vector<int> prime;

    for(int i = 2; i < N; ++i) {
        if(!sieve[i])
            prime.push_back(i);
        for(int j = 0; i * prime[j] < N; ++j) {
            sieve[i * prime[j]] = true;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int getNext(int num, int pos, int change) {
    switch(pos) {
    case 0:
        return num % 1000 + change * 1000;
    case 1:
        return num % 100 + change * 100 + num / 1000 * 1000;
    case 2:
        return num % 10 + change * 10 + num / 100 * 100;
    case 3:
        return change + num / 10 * 10;
    }

    return -1;
}

void BFS() {
    if(m == p) {
        cout << 0 << '\n';
        return;
    }

    vector<int> dp(N, INF);
    dp[m] = 0;

    queue<int> q;
    q.push(m);
    int temp;
    int next;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(i == 0 && j == 0)
                    continue;

                next = getNext(temp, i, j);

                if(sieve[next] == true || dp[next] <= dp[temp])
                    continue;

                dp[next] = dp[temp] + 1;
                q.push(next);
            }
        }
    }

    cout << dp[p] << '\n';
}

int main() {
    init_sieve();

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> m >> p;

        BFS();
    }

    return 0;
}
