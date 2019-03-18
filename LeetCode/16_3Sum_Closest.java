class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans = 0;
        int min = Integer.MAX_VALUE;
        
        Arrays.sort(nums);
        
        for(int i=0; i<nums.length-2; ++i){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            int left = i+1;
            int right = nums.length-1;
            int twoSumTarget = target - nums[i];
            while(left<right){
                if(min > Math.abs(nums[i]+nums[left]+nums[right] - target)){
                    ans = nums[i]+nums[left]+nums[right];
                    min = Math.abs(nums[i]+nums[left]+nums[right] - target);
                }
                
                if(nums[left]+nums[right] > twoSumTarget){
                    right--;
                } else{
                    left++;
                }
            }
        }
        
        return ans;
    }
}
