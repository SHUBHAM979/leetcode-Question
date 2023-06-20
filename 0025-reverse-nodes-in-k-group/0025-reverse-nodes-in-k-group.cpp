/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* rhead = head, *firsthead, *prevsthead = nullptr;
        
        int n=0;
        while(rhead) {
            if(n ==k-1) {
                firsthead= rhead; 
            }
            rhead =rhead->next;
            
            n++;
        }
        rhead = head;
        while(rhead) {
            int i =0;
            stack<ListNode*> st;
            while( i <k) {
                st.push(rhead);
                rhead = rhead->next;
                if(!rhead && i != k-1 ) return firsthead;
                i++;
            }
            while(!st.empty()) {
               
                ListNode* goat = st.top();
                st.pop();
                 if(prevsthead) {
                    prevsthead->next = goat;
                     prevsthead= nullptr;
                }
                if(!st.empty()) {
                    goat->next = st.top();
                }else {
                    goat->next = rhead;
                    prevsthead = goat;
                }
            }
        }
        return firsthead;
        
    }
};