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
    vector<int> ans;
public:
    void findParent(TreeNode* root, map<TreeNode*, TreeNode*> &mp) {
        if(!root) return;
       
        if(root->left) {
            mp[root->left] = root;
            findParent(root->left, mp);
        } 
        if(root->right) {
            mp[root->right] = root;
            findParent(root->right,mp);
        }
        
    }
    
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*> mp, int k, int dist, map<TreeNode*, int>& mnp ) {
      if(!root) return ;
        if(dist == k && root) {
            ans.push_back(root->val);
        }
        mnp[root] =1;
        if(root->left && mnp[root->left] == 0 ) {
            dfs(root->left, mp, k, dist+1, mnp);
        }
         if(root->right && mnp[root->right] == 0 ) {
            dfs(root->right, mp, k, dist+1, mnp);
        }
        if(mnp[mp[root]] == 0) {
            dfs(mp[root], mp, k, dist+1,mnp);
        }
        
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*, TreeNode*> mp;
        mp[root] = nullptr;
        findParent(root, mp);
        map<TreeNode*, int> mnp;
        dfs(target, mp,k, 0, mnp);
        return ans;
        
    }
};