#include <iostream>
#include <vector>

using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define ll long long
#define Inf 0x3fffffff

inline int rit() {
    int f = 0, key = 1;
    char c;
    do {
        c = getchar();
        if(c == '-') key = -1;
    } while(c < '0' || c > '9');

    do {
        f = f * 10 + c - '0';
        c = getchar();
    } while(c >= '0' && c <= '9');

    return f * key;
}

int cnt_edge = 0;

struct Edge {
    int from;
    int to;
    int w;
};

int main() {
    _

    int V, E;
    cout << "Input number of Vertex and Edges: \n";
    V = rit();
    E = rit();

    cout << "Input edge and weight (3 4 -1): \n";

    vector<Edge> edge(E);
    for(int i = 0; i < E; i++) {
        edge[i].from = rit();
        edge[i].to = rit();
        edge[i].w = rit();
    }

    cout << "Input a vertex to detect negative cycle: ";

    vector<int> dist(V, Inf);

    int src = rit();

    dist[src] = 0;

    // Do V-1 times to get shortest path
    for(int i = 0; i < V - 1; ++i) {
        for(int j = 0; j < E; ++j) {
            int u = edge[j].from;
            int v = edge[j].to;
            int w = edge[j].w;

            if(dist[u] != Inf && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // The above step guarantees the shortest path.
    // So if we get a shorter path below, then it means there is a negative cycle.
    for(int i = 0; i < E; ++i) {
        int u = edge[i].from;
        int v = edge[i].to;
        int w = edge[i].w;

        if(dist[u] != Inf && dist[u] + w < dist[v]) {
            cout << "There is a negative cycle.\n";
            return 0;
        }
    }

    cout << "No negative cycle detected.\n";

    return 0;
}
