#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define pci pair<char, int>
#define mp(a, b) (make_pair(a, b))

using namespace std;

int main() {
    _
    int T;
    int n;
    queue<pci> coin;
    vector<pci> finished;
    finished.reserve(100000);
    cin >> T;
    while(T--) {
        finished.clear();

        cin >> n;
        pci temp;
        for(int i = 0; i < n; ++i) {
            cin >> temp.first >> temp.second;
            coin.push(temp);
        }

        while(!coin.empty()) {
            pci now = coin.front();

            if(now.second % 3 == 0) {
                coin.pop();
                if(coin.front().first == finished.back().first) {
                    coin.front().second += finished.back().second;
                    finished.pop_back();
                }

                if(now.first == coin.back().first && coin.size())
                    coin.back().second += now.second / 3;
                else {
                    now.second /= 3;
                    coin.push(now);
                }
            } else {
                if(now.second < 3) {
                    coin.pop();
                    finished.push_back(now);
                } else {
                    coin.front().second = now.second % 3;
                    now.second /= 3;
                    if(coin.back().first == now.first && coin.size())
                        coin.back().second += now.second;
                    else
                        coin.push(now);
                }
            }

        }
        int sum = 0;
        for(vector<pci>::iterator it = finished.begin(); it != finished.end(); ++it)
            sum += it->second;
        cout << sum << '\n';
    }
    return 0;
}
