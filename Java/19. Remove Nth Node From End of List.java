class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(-1, head);

        for (int i = 0; i < n; i++)
            head = head.next;

        ListNode deleteNode = dummyHead;
        while (head != null) {
            head = head.next;
            deleteNode = deleteNode.next;
        }

        deleteNode.next = deleteNode.next.next;

        return dummyHead.next;
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