#include <iostream>
#include <vector>

using namespace std;

int M, N;
int d[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
vector<vector<int>> map(16, vector<int>(16));
vector<vector<int>> opt(16, vector<int>(16));
vector<vector<int>> flip(16, vector<int>(16));

int get(int x, int y) {
    int cnt = map[x][y];
    for(int i = 0; i < 5; ++i) {
        int x2 = x + d[i][0];
        int y2 = y + d[i][1];
        if(x2 >= 0 && x2 < M && y2 >= 0 && y2 < N)
            cnt += flip[x2][y2];
    }

    return cnt % 2;
}

int cal() {
    for(int i = 1; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(get(i - 1, j))
                flip[i][j] = 1;
        }
    }

    for(int i = 0; i < N; ++i) {
        if(get(M - 1, i))
            return -1;
    }

    int res = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(flip[i][j])
                res++;
        }
    }

    return res;
}

int main() {
    cin >> M >> N;

    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            cin >> map[i][j];

    int res = -1;
    for(int i = 0; i < 1 << N; ++i) {

        for(int k = 0; k < M; ++k)
            fill(flip[k].begin(), flip[k].end(), 0);

        for(int j = 0; j < N; ++j) {
            flip[0][N - 1 - j] = i >> j & 1;
        }

        int cnt = cal();
        if(cnt >= 0 && (res < 0 || res > cnt)) {
            res = cnt;
            opt.assign(flip.begin(), flip.end());
        }
    }

    if(res < 0)
        cout << "IMPOSSIBLE\n";
    else {
        for(int i = 0; i < M; ++i) {
            cout << opt[i][0];
            for(int j = 1; j < N; ++j) {
                cout << ' ' << opt[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
