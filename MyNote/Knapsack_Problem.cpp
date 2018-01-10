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
#include <utility>
#include <algorithm>

using namespace std;

bool myComp(pair<int,int> i, pair<int,int> j){
    return i.second < j.second;
}

int main() {

    int N, W;

    cout << "Number of items： ";
    cin >> N;

    cout << "Weight of backpack： ";
    cin >> W;

    vector<pair<int, int>> item;
    cout << "Input each item's value and weight：\n";
    for(int i=0;i<N;++i){
        int v,w;
        cin >> v >> w;
        item.push_back(make_pair(v,w));
    }

    sort(item.begin(), item.end(), myComp);     // 先用weight從小排到大 以利以下的sum優化增加

    int sum = 0;
    vector<int> c(W+1,0);

    for(int i=0;i<N;++i){
        for(int j=min(W,sum+item[i].second); j >= item[i].second; --j)  // 每次不需要比完W次 只需min(W, sum)次
            c[j] = max(c[j], c[j-item[i].second] + item[i].first);      // 因為若可以全放進去，那解就是全放
        sum += item[i].second;
    }

    cout << c[min(W, sum)] << '\n';

    return 0;
}
