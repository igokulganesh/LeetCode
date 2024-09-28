class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode start = findNodeByPosition(head, left - 1);
        ListNode end = findNodeByPosition(start, right - left + 1);

        if (left == 1)
            return reverseNode(head, end);

        start.next = reverseNode(start.next, end.next);

        return head;
    }

    private ListNode reverseNode(ListNode head, ListNode end) {
        ListNode prev = end.next, next;

        while (head != end) {
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }

        if (head != null)
            head.next = prev;

        return head;
    }

    private ListNode findNodeByPosition(ListNode head, int pos) {
        while (--pos > 0)
            head = head.next;

        return head;
    }

    /* ignore Boiler Code */
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