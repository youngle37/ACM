/*
 * O(NlogN)
 *
 * Greedy and Binary Search
 * Using a vector(v) to store all the list's end element.
 *
 */

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int LIS_Size(vector<int> &s){
    if(s.size() == 0)
        return 0;

    vector<int> v;
    v.push_back(s[0]);

    for(int i=1;i<s.size();++i){
        int n = s[i];

        if(n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
    }

    return v.size();
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> s(n);
    for(int i=0;i<n;++i)
        scanf("%d", &s[i]);

    printf("LIS Size is %d\n", LIS_Size(s));

    return 0;
}
