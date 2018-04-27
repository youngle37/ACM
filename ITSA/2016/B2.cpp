#include <stdio.h>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int main(){  
    int T;  
    scanf("%d", &T);  
    while(T--){  
        int n;  
        scanf("%d", &n);  
  
        vector<int> V(110);
        vector<int> now(60);  
        vector<int> lazy(60);  
  
        for(int i=1;i<=52;++i)  
            now[i] = i;  
  
        for(int i=1;i<=n;++i)  
            scanf("%d", &V[i]);  
  
        
        int temp;  
        for(int i=1;i<=n;++i){  
            temp = V[i];  
            lazy.clear();  
  
            for(int j=temp; j<=52;++j){
                lazy[j-temp+1] = now[j];  
            }  
  
            for(int j=1;j<temp;++j){
                lazy[j+52-temp+1] = now[j];  
            }  
  
            for(int j=1;j<=52;++j)  
                now[j] = lazy[j];  
        }  
        
        printf("%d\n", now[52]);  
    }  
  
    return 0;
}
