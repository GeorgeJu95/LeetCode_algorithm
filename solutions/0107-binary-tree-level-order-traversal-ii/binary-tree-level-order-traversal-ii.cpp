// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
//
//


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
    vector<vector<int> > res;
    
    void DFS(TreeNode* root, int level) {
        if (root == NULL) return;
        if (level == res.size()) {
            res.push_back(vector<int>()); // 当进入左分支，创建一层后，在进入右分支不会重复创建(因为此时的level小于res.size)
        }

        res[level].push_back(root->val); // Add the current value to its level
        DFS(root->left, level+1); // Go to the next level
        DFS(root->right,level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 0);
        return vector<vector<int> > (res.rbegin(), res.rend()); // 反过来构造
    }
};
