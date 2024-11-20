class Solution {

    /* Recursive Approach */
    public ListNode reverseList_recursive(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode next = reverseList(head.next);

        head.next.next = head;
        head.next = null;

        return next;
    }

    /* Iterative Approach */
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        ListNode next;

        while (cur != null) {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    /* ignore-boiler-code */
    public class ListNode {
        public int val;
        public ListNode next;

        public ListNode() {
        }

        public ListNode(int val) {
            this.val = val;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}