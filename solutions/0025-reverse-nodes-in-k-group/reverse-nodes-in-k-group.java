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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // 递归思路
        ListNode curr = head;
        int count = 0;
        while (curr != null && count != k) { // find the k+1 node
            curr = curr.next;
            count++;
        }
        if (count == k) { // if k+1 node is found
            curr = reverseKGroup(curr, k); // k+1 node as head，子任务递归
            // head - 没有反转的部分的头节点, 
            // curr - 已经反转（递归）的部分的头节点;
            while (count-- > 0) { // 反转当前部分的k个节点: 
                ListNode tmp = head.next; // tmp - 未反转部分的下一个头节点
                head.next = curr; // 未反转部分的头节点加入已反转部分，前置 
                curr = head; // 反转部分的头节点更新
                head = tmp; // tmp - 未反转部分的下一个头节点
            }
            head = curr;
        }
        return head;
    }
}
