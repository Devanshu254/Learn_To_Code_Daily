class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0;
        int n = rating.size();
        for(int j=1;j<n-1;j++) {
            int countSmallerLeft = 0, countLargerRight = 0;
            int countLargerLeft = 0, countSmallerRight = 0;
            for(int i=0;i<j;i++) {
                if(rating[i] < rating[j]) {
                    countSmallerLeft++;
                }
                if(rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }
            for(int k=j+1;k<n;k++) {
                if(rating[j] < rating[k]) {
                    countLargerRight++;
                }
                if(rating[j] > rating[k]) {
                    countSmallerRight++;
                }
            }
            teams += countSmallerLeft * countLargerRight;
            teams += countLargerLeft * countSmallerRight;
        }
        return teams;
    }
};