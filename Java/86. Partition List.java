class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode leftDummy = new ListNode();
        ListNode rightDummy = new ListNode();

        ListNode left = leftDummy;
        ListNode right = rightDummy;

        while (head != null) {
            if (head.val < x) {
                left.next = head;
                left = left.next;
            } else {
                right.next = head;
                right = right.next;
            }
            head = head.next;
        }

        right.next = null;
        left.next = rightDummy.next;

        return leftDummy.next;
    }

    /* ignore boiler code */
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
