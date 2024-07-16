/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if(!root) {
        return null;
    }
    if(root == p || root == q) {
        return root;
    }
    // Left and right traversal using recursion.
    const leftLCA = lowestCommonAncestor(root.left, p, q);
    const rightLCA = lowestCommonAncestor(root.right, p, q);
    
    if(leftLCA && rightLCA) {
        return root;
    }
    if(leftLCA) return leftLCA;
    
    return rightLCA;
};