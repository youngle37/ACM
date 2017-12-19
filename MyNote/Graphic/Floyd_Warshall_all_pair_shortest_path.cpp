/*
 * 固定一個中繼點(k)，去查看所有組合的距離是否需要這個點
 */

#include <iostream>
#include <vector>

using namespace std;

#define Inf 1000

void print_dist(vector<vector<int>> &d, int V, int i, int j, int k) {
    cout << "i: " << i << " j: " << j << " k: " << k << '\n';
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            cout << d[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> w(10, vector<int>(10, Inf));
    vector<vector<int>> d(10, vector<int>(10, Inf));

    cout << "Input vertex and edges number: \n";

    int V, E;
    cin >> V >> E;

    cout << "Input edge's weight: \n";

    int src, to, weight;
    for(int i = 0; i < E; ++i) {
        cin >> src >> to >> weight;
        w[src][to] = d[src][to] = weight;
    }

    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

                print_dist(d, V, i, j, k);

                cout << '\n' << '\n';
            }
        }
    }

    return 0;
}
