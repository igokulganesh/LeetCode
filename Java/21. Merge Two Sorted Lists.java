class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = null, cur = null;

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                if (cur == null) {
                    head = list1;
                    cur = head;
                } else {
                    cur.next = list1;
                    cur = cur.next;
                }
                list1 = list1.next;
            } else {
                if (cur == null) {
                    head = list2;
                    cur = head;
                } else {
                    cur.next = list2;
                    cur = cur.next;
                }
                list2 = list2.next;
            }
        }

        if (list1 != null) {
            if (cur == null)
                head = list1;
            else
                cur.next = list1;
        }

        if (list2 != null) {
            if (cur == null)
                head = list2;
            else
                cur.next = list2;
        }

        return head;
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