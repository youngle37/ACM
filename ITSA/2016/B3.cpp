#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> V;
    while(scanf("%d", &n) != EOF)
        V.push_back(n);

    sort(V.begin(), V.end());

    printf("%d\n", V[V.size()/2]);
    return 0;
}
