#include <algorithm>

class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;

        if(num == 0)
            return "0";

        if(num < 0){
            neg = true;
            num *= -1;
        }

        string ans = "";
        while(num != 0){
            ans += num % 7 + '0';
            num /= 7;
        }

        reverse(ans.begin(), ans.end());

        return neg ? "-"+ans : ""+ans;
    }
};
