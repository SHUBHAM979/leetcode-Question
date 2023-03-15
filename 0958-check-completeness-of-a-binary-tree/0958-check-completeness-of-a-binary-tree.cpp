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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> pq;
        pq.push(root);
        vector<int> vt;
        vt.push_back(root->val);
        bool isNull = false;
        while(!pq.empty()) {
           // cout << pq.top()->val << " " ;
            root = pq.front();
             pq.pop();
            if(root->left){ 
                cout << root->left-> val ;
                vt.push_back(root->left->val);
                pq.push(root->left);
            } else 
                vt.push_back(0);
            if(root->right){ 
                cout << root->right->val;
                vt.push_back(root->right->val);
                pq.push(root->right);
            } else
                vt.push_back(0);
           
            
        }cout << "{}";
        for(auto i : vt) {
          //  cout << i<<" ";
            if(i == 0) isNull = true;
            if(i !=0 && isNull == true) return false;
            
        }
        return true;
    }
};