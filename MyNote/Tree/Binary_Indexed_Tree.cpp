#include <iostream>

using namespace std;

int arr[6] = {1, 2, 3, 4, 5, 6};
int bit[6];
int n=5;

int lowbit(int x){ return x&(-x); }

int query(int x){
    int sum=0;
    for(int i=x; i>0; i-= lowbit(i))
        sum += bit[i];
    return sum;
}

void update(int x, int val){
    for(int i=x; i<=n; i+=lowbit(i))
        bit[i] += val;
}

void init(int n){
    for(int x=1; x<=n; ++x)
        bit[x] = 0;
    for(int x=1; x<=n; ++x){
        bit[x] += arr[x];
        int y = x + lowbit(x);
        if(y <= n) bit[y] += bit[x];
    }
}


int main(){
    init(5);
    
    cout << query(4) - query(3) << '\n';

    for(int i=1;i<=5;++i)
        cout << bit[i] << ' ';

    return 0;
}
