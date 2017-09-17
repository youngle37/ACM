#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){ _

    int i, j;
    int count;
    int MAX;
    int temp;
    while(cin >> i >> j){
        cout << i << " " << j << " ";
        
        MAX = 0;
        if(i > j){
            temp = j;
            j = i;
            i = temp;
        }

        for(int t=i ; t<=j ; ++t){
            count = 1;
            temp = t;
            while(temp != 1){
                ++count;

                if(temp%2 == 1)
                    temp = 3*temp +1;
                else
                    temp /=2;
            }

            MAX = MAX < count ? count : MAX;

        }

        cout << MAX << '\n';
    }

    return 0;
}
