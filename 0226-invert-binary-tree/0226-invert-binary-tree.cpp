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
    void postOrder (TreeNode* head ) {
        if(!head) return;
        postOrder(head->left);
        postOrder(head->right);
        swap(head->left, head->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        postOrder(root);
        return root;
        
    }
};