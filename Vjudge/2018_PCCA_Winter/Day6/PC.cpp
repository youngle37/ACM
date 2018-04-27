#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rect{
    int w;
    int h;
};

bool myComp(rect a, rect b){
    if(a.w == b.w)
        return a.h > b.h;
    else
        return a.w < b.w;
}

int main(){
    int n;
    while(cin >> n && n != -1){
        vector<rect> r(1001);

        for(int i=0;i<n;++i)
            scanf("%d %d", &r[i].w, &r[i].h);

        sort(r.begin(), r.begin()+n, myComp);

        int ans = 0,  w0 = 0;
        int w;
        int h1, h2;
        for(int i=0;i<n;++i){
            w = r[i].w;
            h1 = r[i].h;
            h2 = r[i+1].h;

            ans += (w - w0) * (w - w0);
            ans += 
        }

    }

    return 0;
}
