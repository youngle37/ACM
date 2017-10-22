#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
    _

    int T;
    int n;
    int swa;
    cin >> T;

    vector<int> carr;
    carr.resize(51);

    while(T--){
        cin >> n;

        for(int i=0;i<n;++i)
            cin >> carr[i];

        swa = 0;
        for(int i=n-1;i>0;--i){
            for(int j=0;j<i;++j){
                if(carr[j] > carr[j+1]){
                    ++swa;
                    swap(carr[j], carr[j+1]);
                }
            }
        }
        cout << "Optimal train swapping takes " << swa << " swaps.\n";
    }

    return 0;
}
