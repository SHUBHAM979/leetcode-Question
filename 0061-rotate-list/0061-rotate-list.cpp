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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* rhead = head, *lastnode;
        int n =0;
        while(rhead) {
            n++;
            lastnode = rhead;
            rhead = rhead->next;
        }
        ListNode* knode;
        rhead = head;
        int i=0;
        k=k%n;
        cout << k;
        if( k ==0 ) return head;
        while(i<n-k) {
            i++;
            knode = rhead;
            rhead = rhead ->next;
        }
        lastnode -> next= head;
        knode -> next = NULL;
        return rhead;
        
        
        
        
    }
};