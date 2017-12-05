#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

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

bool myComparator (pii a, pii b) {
    return a.first < b.first;
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return (2 * i + 1);
}

int right(int i) {
    return (2 * i + 2);
}

void MaxHeapify(vector<int> &max_heap, int &size, int i) {
    int l = left(i);
    int r = right(i);
    int biggest = i;

    if(l < size && max_heap[l] > max_heap[biggest])
        biggest = l;
    if(r < size && max_heap[r] > max_heap[biggest])
        biggest = r;

    if(biggest != i) {
        swap(max_heap[i], max_heap[biggest]);
        MaxHeapify(max_heap, size, biggest);
    }
}

void heap_insert(vector<int> &max_heap, int &size, int k) {
    ++size;
    int i = size - 1;
    max_heap[i] = k;

    while(i != 0 && max_heap[parent(i)] < max_heap[i]) {
        swap(max_heap[i], max_heap[parent(i)]);
        i = parent(i);
    }
}

int heap_extractMax(vector<int> &max_heap, int &size) {
    if(size <= 0)
        return -1;
    if(size == 1) {
        --size;
        return max_heap[0];
    }

    int root = max_heap[0];
    max_heap[0] = max_heap[--size];
    MaxHeapify(max_heap, size, 0);

    return root;
}

void solve() {
    int n = rit();

    vector<int> exe_time(n);
    vector<pii> deadline(n);
    for(int i = 0; i < n; ++i) {
        exe_time[i] = rit();
        deadline[i] = mp(rit(), i);
    }

    sort(deadline.begin(), deadline.end(), myComparator);

    vector<int> max_heap;
    max_heap.reserve(n);
    int size = 0;

    int acc_time = 0;
    for(int i = 0; i < n; ++i) {
        acc_time += exe_time[deadline[i].second];

        heap_insert(max_heap, size, exe_time[deadline[i].second]);

        if(acc_time > deadline[i].first)
            acc_time -= heap_extractMax(max_heap, size);
    }

    cout << size << '\n';
}

int main() {
    _

    int T = rit();

    while(T--)
        solve();

    return 0;
}
