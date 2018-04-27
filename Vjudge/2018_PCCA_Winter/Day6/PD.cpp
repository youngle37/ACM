#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<int> remain;

        int temp;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            remain.push_back(temp);
        }

        sort(remain.begin(), remain.end());

        if(remain.size() == 1){
            printf("%d\n", remain[0]);
            printf("%d\n", remain[0]);

            if(T!=0)
                printf("\n");
            continue;
        }

        vector<int> line;
        int ans = 0;
        int l, ll, s, ss;
        ss = remain[0];
        s = remain[1];
        while(remain.size() > 3){
            ll = remain.back();
            remain.pop_back();
            l = remain.back();
            remain.pop_back();

            if(ss+2*s+ll > 2*ss+l+ll){
                ans += 2*ss+l+ll;
                line.push_back(ss);
                line.push_back(l);
                line.push_back(ss);
                line.push_back(ss);
                line.push_back(ll);
                line.push_back(ss);
            }else{
                ans += ss+2*s+ll;
                line.push_back(ss);
                line.push_back(s);
                line.push_back(ss);
                line.push_back(l);
                line.push_back(ll);
                line.push_back(s);
            }
        }
        if(remain.size() == 3){
            ans += remain[0] + remain[1] + remain[2];
            line.push_back(remain[0]);
            line.push_back(remain[2]);
            line.push_back(remain[0]);
            line.push_back(remain[0]);
            line.push_back(remain[1]);
        }
        else{
            ans += max(remain[0], remain[1]);
            line.push_back(remain[0]);
            line.push_back(remain[1]);
        }

        printf("%d\n", ans);

        printf("%d %d\n", line[0], line[1]);
        for(int i=2;i<line.size();++i){
            printf("%d\n%d %d\n", line[i], line[i+1], line[i+2]);
            i+=2;
        }

        if(T != 0)
            printf("\n");
    }

    return 0;
}
