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
    ListNode* reverseList(ListNode* head) {
        ListNode* top = head;
        ListNode *temp = NULL,* mem = head;
        while(head) {
            if(temp) {
                ListNode* prev =  head-> next;
                head->next = mem;
                mem =head;
                temp = prev;
            } else {
                temp = head-> next;
                head->next = NULL;
                mem =head;
                
            }
            head = temp;
        }
        return mem;
        
        
        
    }
};