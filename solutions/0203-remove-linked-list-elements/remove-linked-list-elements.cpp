// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) {
            if(head->val == val)
                return nullptr;
            else return head;
        }
        while(head != nullptr && head->val == val) head = head->next;
        if(head == nullptr) return head;
        if(head->next == nullptr) 
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p2) {
            if(p2->val == val) {
                while(p2 != nullptr && p2->val == val) {
                    p2 = p2->next;
                } 
                p1->next = p2;
                if(p1->next == nullptr) return head;
                else p2 = p1->next;
            }
            else {
                p1 = p2;
                p2 = p2->next;
            }
        }
        return head;
    }
};
