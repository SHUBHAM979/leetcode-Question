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
        TreeNode *leftNode = head->right;
        TreeNode* rightNode = head->left;
        head->left = leftNode;
        head->right = rightNode;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        postOrder(root);
        return root;
        
    }
};