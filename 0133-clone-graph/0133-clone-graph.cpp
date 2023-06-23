/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node ) {
           map<int,int> vis;
        queue<Node*> qu;
        qu.push(node);
        while(!qu.empty()) {
            
            Node* current_node = qu.front();
            qu.pop();
            if(vis[current_node->val] ==1) continue;
            cout << current_node->val << " ";
            vis[current_node->val] =1;
            for(auto i : current_node->neighbors) {
                if(vis[i->val] != 1) {
                    qu.push(i);
                }
            }
        }
       
        
    }
    
    Node* cloneGraph(Node* node) {
     if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*> mem;
        queue<pair<Node*, Node*>> qu;
        Node * rhead = new Node(node->val);
        mem[node] = rhead;
        qu.push({node,rhead});
        while(!qu.empty()) {
            
            pair<Node*, Node*> current_node = qu.front();
            qu.pop();
            
            
           // cout << current_node.first->val << " ";
           
            for(auto i : current_node.first->neighbors) {
                if(mem.find(i) == mem.end()) {
                    Node* temp =new Node(i->val);
                    qu.push({i,temp});
                    mem[i] = temp;
                    current_node.second->neighbors.push_back(temp);
                }else {
                    current_node.second->neighbors.push_back(mem[i]);
                }
            }
        }
        cout << "l";
        dfs(rhead);
        return rhead;
    }
};