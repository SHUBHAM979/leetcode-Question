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
      TreeNode* Clone(TreeNode* root) {
    TreeNode* new_root = new TreeNode(0);
    new_root->left = (root->left) ? Clone(root->left) : nullptr;
    new_root->right = (root->right) ? Clone(root->right) : nullptr; 
    return new_root;
  } 
    
    vector<TreeNode*> clone( vector<TreeNode*> head) {
        vector<TreeNode*> res;
        for(auto top : head) {
            TreeNode* rhead = Clone(top);
            res.push_back(rhead);
            
        }
        return res;
    }
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};
        vector<vector<TreeNode*>> dp(n+1);
        dp[1].push_back(new TreeNode(0));
        for(int i = 3 ;i <=n ; i+=2) {
            for(int j =1; j<i; j+=2) {
                vector<TreeNode*> leftsub , rightsub;
                leftsub = clone(dp[j]);
                rightsub = clone(dp[i-j-1]);
                for(auto left : leftsub) {
                    for(auto right : rightsub) {
                        TreeNode* head = new TreeNode(0, left, right);
                        dp[i].push_back(head);
                    }
                }
            }
            
        }
        return dp[n];
    }
};