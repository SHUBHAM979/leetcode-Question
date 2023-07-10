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
    vector<TreeNode*> rec(int start , int end) {
       vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        if(start == end) {
            res.push_back(new TreeNode(start)) ;
            return res;
        }
        
        for(int i = start; i <=end; i++) {
            vector<TreeNode*> leftSubTree = rec(start, i-1);
            vector<TreeNode*> rightSubTree = rec(i+1 , end);
            for(auto left : leftSubTree) {
             for(auto right : rightSubTree) {
                TreeNode*  head = new TreeNode(i);
                head->left = left;
                head -> right = right;
                 res.push_back(head);
             }
            }
            
        }
        
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
        
        
    }
};