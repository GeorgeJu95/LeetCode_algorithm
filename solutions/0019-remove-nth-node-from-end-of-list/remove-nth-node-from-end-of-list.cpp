// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 有头节点版本
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; ++i) {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
