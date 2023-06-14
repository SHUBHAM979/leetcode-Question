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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        if(!list1) return list2;
        if(!list2) return list1;
        head = new ListNode(0);
        ListNode * rhead =head;
        while(list1 && list2) {
            if(list1->val <= list2->val ) {
                head-> val = list1->val;
                list1 = list1->next;
                head->next = new ListNode(0);
                head = head->next;
            } else {
                    head-> val = list2->val;
                list2 = list2->next;
                head->next = new ListNode(0);
                head = head->next;
            } 
        }
        
        while(list1) {
            head-> val = list1->val;
                list1 = list1->next;
                head->next = new ListNode(0);
                head = head->next;
            
        }
        while(list2) {
              head-> val = list2->val;
                list2 = list2->next;
                head->next = new ListNode(0);
                head = head->next;
        }
        ListNode * mhead = rhead;
        while(mhead && mhead ->next &&mhead -> next->next) {
            mhead = mhead->next;
        }
        mhead->next = nullptr;
        return rhead;
    }
};