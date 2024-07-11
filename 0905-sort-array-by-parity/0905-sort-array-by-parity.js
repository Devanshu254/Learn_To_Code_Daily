/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function(nums) {
    let n = nums.length;
    let i=0, j=0;
    while(i<n) {
        if(nums[i] & 1) {
            i++;
        }else {
            let temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j++;
        }
    }
    return nums;
};