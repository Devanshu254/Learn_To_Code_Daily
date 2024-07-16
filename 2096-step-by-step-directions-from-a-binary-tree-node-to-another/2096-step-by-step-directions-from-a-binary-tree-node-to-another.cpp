/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if(!root) return NULL;
        if(root->val == src || root->val == dest) return root;
        // Left and right traversal using recursion.
        TreeNode* LeftLCA = lowestCommonAncestor(root->left, src, dest);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, src, dest);
        // If we get both.
        if(LeftLCA != NULL && rightLCA != NULL) return root;
        // If we get left but not right.
        if(LeftLCA != NULL) return LeftLCA;
        return rightLCA;
    }
    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) return false;
        if(LCA->val == target) return true;
        // Left Explore.
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        };
        path.pop_back();
        // Right Exporation.
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);
        // Create two strings to store the path.
        string lcaToSrc = "";
        string lcaToDest = "";
        // Find the path.
        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue, lcaToDest);
        // String result.
        string result = "";
        // Traversing the lacToSrc.
        for(int i=0;i<lcaToSrc.length();i++) {
            result.push_back('U');
        }
        // For right means lcaToDest.
        result += lcaToDest;    
        return result;
    }
};