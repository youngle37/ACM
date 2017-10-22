/*
 * 對某一件物品可以選擇要放或不放，然後移去這件物品，縮小問題
 *
 * c[n][w] = max( c[n-1][w], c[n-1][w-weight[n]] + cost[n])
 *                   ^不放             ^放
 *
 * n: 第0個到第n個物品要放進背包
 * w: 背包耐重限制
 * c[n][w]: 只有0~n個物品 耐重為w的答案
 * weight[n]: 第n個物品的重量
 * cost[n]: 第n個物品的價值
 *
 * 又因每次計算只需要上方和左上方的格子
 * 可以重複利用記憶體，建立一條陣列即可
 * 不過要從陣列後端開始，不然會覆蓋到左上的格子
 *
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10, W = 20;
int cost[N], weight[N];
vector<int> c(W + 1, 0);

void find_best_value(int n, int w) {

    for(int i = 0; i < n; ++i)                  // 窮舉每種物品
        for(int j = w; j - weight[i] >= 0; --j) // 窮舉每種重量且由後往前
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);

    cout << c[w] << '\n';
}


void init() {
    cout << "Input each item cost:" << '\n';
    for(int i = 0; i < N; ++i)
        cin >> cost[i];

    cout << "Input each item weight: " << '\n';
    for(int i = 0; i < N; ++i)
        cin >> weight[i];
}

int main() {

    init();
    find_best_value(N, W);

    return 0;
}
