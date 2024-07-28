class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int max_count = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == 1) {
                count++;
            }
            if(nums[i] == 0) {
                count = 0;
            }
            max_count = Math.max(count, max_count);
        }
        return max_count;
    }
}