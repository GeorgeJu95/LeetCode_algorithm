// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        return helper(dummy, k);
    }
    
    ListNode* helper(ListNode*& dummy, int k) {
        ListNode* firstDummy = dummy;
        ListNode* head = dummy->next;
        ListNode* p = head;
        bool first = 1;
        while(p) {
            int tmp = k;
            while(--tmp) {
                p = p->next;
                if(!p) return firstDummy->next;
            }
            // if(!p) return firstDummy->next;
            // else {
            ListNode* test = head->next;
            head->next = p->next;
            ListNode* head2 = head;
            while(test != head->next) {
                // ListNode* test = head->next;
                // if(test->next) {
                    ListNode* temp = test->next;                    
                    test->next = head2;
                    head2 = test;
                    test = temp;
                // } else return firstDummy->next;
            }
            // p->next = head;
            if(first) {
                firstDummy->next = p;
                first = 0;
            }
            else dummy->next = p;
            ListNode* t = firstDummy;
            // while(t) {
            //     cout << t->val << " ";
            //     t = t->next;
            // }
            p = head->next;
            dummy = head;
            head = head->next;
            // }
        }
        return firstDummy->next;
    }
};
