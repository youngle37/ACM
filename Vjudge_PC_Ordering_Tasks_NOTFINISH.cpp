#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

#define pii pair<int, int>
#define pib pair<int, bool>
#define mp(a, b) (make_pair(a, b))

using namespace std;

void dfs(){

}

bool check(vector<pib> &indegree, int n){
    for(int i=0;i<n;++i)
        if(!indegree[i].second)
            return true;

    return false;
}

int main(){
    _

    int n, m;
    vector<pib> indegree(100);
    vector<pii> relations;
    vector<int> ans(100);
    int left, right;
    while(cin >> n >> m && (n != 0 || m != 0)){
        relations.resize(m);
        fill(indegree.begin(), indegree.end(), mp(0, false));
        fill(ans.begin(), ans.end(), 0);

        for(int i=0;i<m;++i){
            cin >> left >> right;
            ++indegree[right].first;
            relations[i] = mp(left, right);
        }


        while(check(indegree, n)){
            for(int i=0;i<n;++i){
                if(!indegree[i].first){
                    for()
                }
            }
        }
    }

    return 0;
}
