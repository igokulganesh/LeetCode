class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        int len = findLength(head);

        if (len < 2 || k == 0 || k % len == 0)
            return head;

        k = k % len;
        int n = len - k - 1;
        ListNode cur = head;
        while (n-- > 0) {
            cur = cur.next;
        }

        ListNode newHead = cur.next;
        cur.next = null;

        cur = newHead;
        while (cur.next != null) {
            cur = cur.next;
        }

        cur.next = head;

        return newHead;
    }

    private int findLength(ListNode head) {
        int len = 0;
        while (head != null) {
            head = head.next;
            len++;
        }
        return len;
    }

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
