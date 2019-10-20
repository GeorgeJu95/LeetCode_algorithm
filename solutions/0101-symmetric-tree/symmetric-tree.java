// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//  
//
// But the following [1,2,2,null,3,null,3] is not:
//
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//  
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        
        Stack<TreeNode> S = new Stack<TreeNode>();
        if(root.left != null) {
            if(root.right == null) return false;
            else {
                S.push(root.left);
                S.push(root.right);
            }
        } else if(root.right != null) return false;
        
        while(!S.empty()) {
            if(S.size() % 2 != 0) return false;
            TreeNode right = S.pop();
            TreeNode left = S.pop();
            if(left.val != right.val) return false;
            
            if(left.left != null) {
                if(right.right == null) return false;
                else {
                    S.push(left.left);
                    S.push(right.right);
                }
            } else if(right.right != null) return false;
            
            if(left.right != null) {
                if(right.left == null) return false;
                else {
                    // 注意顺序，先压左边树，在压入右边树
                    S.push(left.right);
                    S.push(right.left);
                }
            } else if(right.left != null) return false;
        }
        
        return true;
    }
}
