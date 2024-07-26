class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = 0; 
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        int count = n*(n+1)/2;
        int result = (count - sum);
        return result;
    }
}