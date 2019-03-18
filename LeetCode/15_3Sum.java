class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        if(nums == null || nums.length < 3)
            return ans;
        
        Arrays.sort(nums);
        
        for(int i=0; i<nums.length-2; ++i){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int left = i+1;
            int right = nums.length-1;
            int target = -nums[i];
            while(left<right){
                if(nums[left]+nums[right] == target){
                    ans.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if(nums[left]+nums[right] > target){
                    right--;
                } else{
                    left++;
                }
            }
        }
        
        return ans;
    }
}
