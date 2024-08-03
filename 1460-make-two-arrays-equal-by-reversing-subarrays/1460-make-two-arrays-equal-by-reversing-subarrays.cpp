class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n = target.size();
        for(int i=0;i<n;i++) {
            mpp[target[i]]++;
        }
        for(int i=0;i<n;i++) {
            if(mpp.find(arr[i])!= mpp.end()) {
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0) {
                    mpp.erase(arr[i]);
                }
            }
        }
        if(!mpp.empty()) {
            return false;
        }
        return true;
    }
};