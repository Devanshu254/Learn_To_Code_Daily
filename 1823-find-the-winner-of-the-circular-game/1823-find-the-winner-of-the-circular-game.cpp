class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize an array. 
        vector<int> arr;
        // Fill the array with i values. 
        for(int i=0;i<n;i++) {
            arr.push_back(i+1);
        }
        int index = 0;
        while(arr.size() > 1) {
            // Calculate the index which is to be erased.
            index = (index + (k-1))% arr.size();
            // Erase the index.
            arr.erase(arr.begin() + index);
        }
        // Return the first element of the list.
        return arr[0];
    }
};
// Time Complexity: O(N) + O(N) * O(N) = O(N^2).
// Space Complexity: O(N) -> Using an extra array.