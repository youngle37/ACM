#include <iostream>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

#define N 100

using namespace std;

struct Edge {
    int to;
    int w;
    int next;
} edge[N * 2];

int cnt_edge = 0;
int head[N * 2];

void add_edge(int from, int to, int w) {
    edge[cnt_edge].to = to;
    edge[cnt_edge].w = w;
    edge[cnt_edge].next = head[from];
    head[from] = cnt_edge++;
}

int main() {
    _

    memset(head, -1, sizeof(head));

    int edge_number;
    cout << "Input edge number: ";
    cin >> edge_number;

    cout << "Input edge start, end, weight: " << '\n';
    int from, to, w;
    for(int i = 0; i < edge_number; ++i) {
        cin >> from >> to >> w;
        add_edge(from, to, w);
    }


    int node;
    while(true) {
        cout << "Input the node you want to traversal its neighbors:";
        cin >> node;

        for(int i = head[node]; ~i ; i = edge[i].next) // when i != -1 then continue
            cout << edge[i].to << ' ';

        cout << '\n';
    }

    return 0;
}
