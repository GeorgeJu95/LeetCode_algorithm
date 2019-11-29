// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        return reverseRecursive(head, tail);
    }

    ListNode* reverseRecursive(ListNode *head, ListNode *&tail) {
        // 每次需要保存已经reverse的链表的头节点head和尾节点tail
        if (head == nullptr) {
            tail = nullptr;
            return head;
        }
        if (head->next == nullptr) {
            tail = head;
            return head;
        }
        auto h = reverseRecursive(head->next, tail);
        // 用tail做挂载点，每次递归返回后，head挂在其上，并让null接在head后面达到reverse目的
        if (tail != nullptr) {
            tail->next = head;
            tail = head;
            head->next = nullptr;
        }
        return h;
    }
};
