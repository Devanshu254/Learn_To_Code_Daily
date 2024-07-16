/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root == p || root == q) {
            return root;
        }
        
        // Left and right traversal and calculation.
        TreeNode* LeftT = lowestCommonAncestor(root->left, p, q);
        TreeNode* RightT = lowestCommonAncestor(root->right, p, q);
        
        if(LeftT != NULL && RightT != NULL) {
            return root;
        }
        
        if(LeftT != NULL) {
            return LeftT;
        }
        
        return RightT;
    }
};