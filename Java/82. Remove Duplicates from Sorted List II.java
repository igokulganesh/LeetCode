class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode dummyHead = new ListNode(0, head);
        ListNode prev = dummyHead;

        for (ListNode cur = head; cur != null; cur = cur.next) {
            if (cur.next != null && cur.val == cur.next.val) {
                while (cur.next != null && cur.val == cur.next.val)
                    cur = cur.next;
                prev.next = cur.next;
            } else {
                prev = cur;
            }
        }

        return dummyHead.next;
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