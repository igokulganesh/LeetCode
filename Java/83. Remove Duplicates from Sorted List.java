class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        for (ListNode cur = head; cur != null; cur = cur.next) {
            ListNode next = cur.next;
            while (next != null && cur.val == next.val)
                next = next.next;
            cur.next = next;
        }

        return head;
    }

    /* ignore Boiler code */
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