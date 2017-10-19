/* Disjoint set's find and union function
 *
 * q[x] = x 會去問的人
 *  若小於零代表自己就是boss
 *  而負數代表這個集合的大小
 *
 * 在問用repr問x的boss是誰時順便做壓縮
 * uni時 判定數量的大小再合併 把小群併到大群
 *
 */
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int repr(vector<int> &q, int x) {
    return q[x] < 0 ? x : q[x] = repr(q, q[x]);
}

void uni(vector<int> &q, int x, int y) {
    int a = repr(q, x);
    int b = repr(q, y);

    if(a != b) {
        if(q[a] < q[b]) { // size of a is bigger than b
            q[a] += q[b];
            q[b] = a;
        } else {
            q[b] += q[a];
            q[a] = b;
        }
    }
}

int main() {
    int n;
    char cmd[100]; // f stand for find, u stand for union

    cin >> n;
    vector<int> q(n, -1);
    while(scanf("%s", cmd) == 1) {
        int x, y;

        if(cmd[0] == 'u') {
            cin >> x >> y;
            uni(q, x, y);
        } else {
            cin >> x;
            cout << repr(q, x) << endl;
        }

        for(int i = 0; i < n; ++i) {
            cout << q[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
