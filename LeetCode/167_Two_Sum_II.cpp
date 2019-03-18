class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++){
            int comple = target - numbers[i];
            int idx = binary_search(numbers, 0, numbers.size(), comple);
            if(idx != -1){
                vector<int> ret;
                if(i == idx){
                    ret.push_back(i+1);
                    ret.push_back(i+2);
                }else {
                    ret.push_back(i+1);
                    ret.push_back(idx+1);
                }
                return ret;
            }
        }

        vector<int> never;
        return never;
    }

    int binary_search(vector<int>& arr, int l, int r, int v) {
        while(l <= r) {
            int mid = (l+r) / 2;
            if(v > arr[mid])
                l = mid + 1;
            else if(v < arr[mid])
                r = mid - 1;
            else
                return mid;
        }

        return -1;
    }
};
