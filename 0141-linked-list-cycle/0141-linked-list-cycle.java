/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null || head.next==null)return false;
        ListNode start=head.next;
        ListNode end=head;

        while(start!=null && start.next!=null){
            if(start==end){
                return true;
            }
            start=start.next.next;
            end=end.next;
        }
        return false;
    }
}