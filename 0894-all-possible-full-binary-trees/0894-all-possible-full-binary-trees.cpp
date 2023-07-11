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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};
        vector<TreeNode*> res;
        if(n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        for(int i =1 ; i < n; i +=2) {
            vector<TreeNode*> leftSubtree = allPossibleFBT(i);
            vector<TreeNode*> rightSubtree = allPossibleFBT(n-1 - i);
            for(auto left : leftSubtree) {
                for(auto right : rightSubtree) {
                    TreeNode* root = new TreeNode(0, left, right);
                    res.push_back(root);
                }
            }
            
        }
        return res;
    }
};