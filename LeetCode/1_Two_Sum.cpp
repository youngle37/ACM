#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        for(int i = 0; i < nums.size(); i++) {
            int comple = target - nums[i];
            map<int, int>::iterator it = table.find(comple);
            if(it != table.end()){
                vector<int> ret{ it->second, i };
                return ret;
            }
            table[nums[i]] = i;
        }
        
        vector<int> never;
        return never;
    }
};
