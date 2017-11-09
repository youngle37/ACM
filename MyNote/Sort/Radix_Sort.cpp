#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    int N;
    vector<int> data;
    cout << "Enter the size of unsorted number:";
    cin >> N;

    data.resize(N);

    int MAX = -1;
    for(int i = 0; i < N; ++i){
        cin >> data[i];
        MAX = data[i] > MAX ? data[i] : MAX;
    }

    vector<vector<int>> bucket(10, vector<int>(N));
    vector<int> count(10, 0);

    int radix = 1;

    int LSD;
    int index;
    while(radix <= MAX) {
        for(int i = 0; i < data.size(); ++i) {
            LSD = (data[i] / radix) % 10;
            bucket[LSD][count[LSD]] = data[i];
            ++count[LSD];
        }

        radix *= 10;

        index = 0;
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < count[i]; ++j)
                data[index++] = bucket[i][j];
            count[i] = 0;
        }
    }

    for(int i = 0; i < data.size(); ++i)
        cout << data[i] << ' ';
    cout << '\n';

    return 0;
}
