#include <iostream>
#include <vector>

using namespace std;

// Number of vertices
#define N 10

// Global time counter
int t = 0;

struct Edge {
    int src;
    int dest;
};

void create_adjList(vector<vector<int>> &adjList, vector<Edge> &edges) {
    int src;
    int dest;

    for(int i = 0; i < edges.size(); ++i) {
        src = edges[i].src;
        dest = edges[i].dest;

        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
}

int DFS(vector<vector<int>> &adjList, int v, vector<int> &visit, int parent) {
    visit[v] = ++t;

    int arr = visit[v];

    for(vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) {
        if(!visit[*it])
            arr = min(arr, DFS(adjList, *it, visit, v));
        else if(*it != parent)
            arr = min(arr, visit[*it]);
    }

    if(arr == visit[v] && parent != -1){
        cout << parent << " <-> " << v << '\n';
    }

    return arr;
}

int main() {
    vector<Edge> edges = {
        {0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}
    };

    vector<vector<int>> adjList(N, vector<int>());
    create_adjList(adjList, edges);

    vector<int> visit(N, 0);

    int start = 0;
    int parent = -1;

    DFS(adjList, start, visit, parent);

    return 0;
}
