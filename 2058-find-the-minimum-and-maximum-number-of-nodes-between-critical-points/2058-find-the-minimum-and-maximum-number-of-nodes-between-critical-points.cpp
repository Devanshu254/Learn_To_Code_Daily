/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Create critical points vector.
        vector<int> criticalPoints;
        int index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        // Calculating Critical Points.
        while(curr && curr->next) {
            if((curr->val > prev->val && curr->val > curr->next->val) || 
            (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        // Compare if critical points are less than 2.
        int n = criticalPoints.size();
        if(n < 2) return {-1,-1};
        // Calculate minDistance and maxDistance.
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back()-criticalPoints.front();
        // return minDistance and maxDistance.
        for(int i=1;i<n;i++) {
            minDistance = min(minDistance, criticalPoints[i]-criticalPoints[i-1]);
        }
        return {minDistance, maxDistance};
    }
};