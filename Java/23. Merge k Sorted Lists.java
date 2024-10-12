class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = null;

        for (ListNode list : lists)
            head = mergeTwoList(head, list);

        return head;
    }

    private ListNode mergeTwoList(ListNode head1, ListNode head2) {
        ListNode dummy = new ListNode();
        ListNode cur = dummy;

        while (head1 != null && head2 != null) {
            if (head1.val < head2.val) {
                cur.next = head1;
                head1 = head1.next;
            } else {
                cur.next = head2;
                head2 = head2.next;
            }
            cur = cur.next;
        }

        if (head1 != null)
            cur.next = head1;

        if (head2 != null)
            cur.next = head2;

        return dummy.next;
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