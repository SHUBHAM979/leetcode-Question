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
    int dfs(TreeNode* root) {
        if(!root -> left && !root->right) {
            return 1;
        }
        int x =INT_MAX;
        if(root->left) {
            x = 1+ dfs(root->left);
        } 
        if(root->right) {
            x = min(x, 1+ dfs(root->right));
        }
        return x;
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
        
        
    }
};