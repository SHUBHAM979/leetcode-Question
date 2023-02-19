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
    void preorder(int level, TreeNode* root, map<int,vector<int>> &mp) {
        if(!root) return;
        mp[level].push_back(root->val);
        preorder(level+1,root->left,mp);
        preorder(level+1,root->right,mp);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        preorder(0,root, mp);
        vector<vector<int>> res;
        int j=0;
        for(auto i : mp) {
            if(j%2 ==0) {
                res.push_back(i.second);
            }else {
                reverse(i.second.begin(),i.second.end());
                res.push_back(i.second);
                
            }
            j++;
        }
        return res;
        
    }
};