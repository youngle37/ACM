#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    long long n;
    int k;
    vector<long long> ans;
    while(cin >> n >> k){
        ans.clear();

        for(long long i=1; i*i<=n; ++i){
            if(n % i == 0)
                ans.push_back(i);
        }

        long long temp = ans.size();
        if(n/ans.back() == ans.back())
            --temp;
        for(long long i=temp-1; i>=0; --i)
            ans.push_back(n/ans[i]);

        for(int i=0;i<ans.size(); ++i)
            cout << ans[i] << ' ';

        if(k > ans.size())
            cout << -1 << '\n';
        else
            cout << ans[k-1] << '\n';

    }

    return 0;
}
