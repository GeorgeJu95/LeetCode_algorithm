// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            ++ans;
            // 保证处理同一层的ans不变，左边不为叶节点，但是右边为叶节点
            // 而且要注意要把Q.size()拿出来，不然pop后会导致size出问题
            int k = Q.size();
            for(int i=0; i<k; ++i) {
                TreeNode* q = Q.front();
                if(!q->left && !q->right) return ans;
                if(q->left) Q.push(q->left);
                if(q->right) Q.push(q->right);
                Q.pop();
            }
        }
        
        return -1;
    }
};
