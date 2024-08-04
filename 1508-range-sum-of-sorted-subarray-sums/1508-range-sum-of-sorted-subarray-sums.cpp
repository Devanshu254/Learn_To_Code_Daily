class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> SubArraySum;
        for(int i=0;i<n;i++) {
            int currSum = 0;
            for(int j=i;j<n;j++) {
                currSum += nums[j];
                SubArraySum.push_back(currSum);
            }
        }
        sort(SubArraySum.begin(), SubArraySum.end());
        long long result = 0;
        const int mod = 1e9+7;
        for(int i=left-1;i<right;i++) {
            result = (result + SubArraySum[i]) % mod;
        }
        return result;
    }
};