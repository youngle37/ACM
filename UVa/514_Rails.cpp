#include <stdio.h>
#include <vector>

using namespace std;

int n;

int main(){
    while(scanf("%d", &n) && n){
        vector<int> target(n);
        vector<int> stack;

        while(scanf("%d", &target[0])){
            if(target[0] == 0){
                printf("\n");
                break;
            }
            for(int i=1;i<n;++i)
                scanf("%d", &target[i]);

            int left=0, right=0;
            while(1){
                if(!stack.empty() && stack.back() == target[left]){
                    left++;
                    stack.pop_back();
                    continue;
                }
                if(right >= n)
                    break;
                stack.push_back(right+1);
                right++;
            }

            if(stack.empty())
                printf("Yes\n");
            else
                printf("No\n");

            stack.clear();
        }
    }

    return 0;
}
