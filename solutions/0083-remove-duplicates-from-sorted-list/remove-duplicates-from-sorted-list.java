// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
//
//
// Input: 1->1->2
// Output: 1->2
//
//
// Example 2:
//
//
// Input: 1->1->2->3->3
// Output: 1->2->3
//
//


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) return head;
        ListNode dummy = new ListNode(0);
        ListNode firstDummy = dummy;
        dummy.next = head;
        while(head != null && head.next != null) {
            if(head.next.val != head.val) {
                dummy.next = head;
                dummy = head;
                head = head.next;
            } else {
                head = head.next;
            }
        }
        if(dummy == firstDummy)
            return new ListNode(head.val);
        if(head != null && head.val != dummy.val)
            dummy.next = head;
        return firstDummy.next;
    }
}
