class Solution {
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

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null, cur = null;
        int carry = 0, sum;
        while (l1 != null && l2 != null) {
            sum = l1.val + l2.val + carry;
            carry = sum / 10;

            if (cur == null) {
                head = new ListNode(sum % 10);
                cur = head;
            } else {
                cur.next = new ListNode(sum % 10);
                cur = cur.next;
            }
            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null) {
            sum = l1.val + carry;
            carry = sum / 10;
            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            l1 = l1.next;
        }

        while (l2 != null) {
            sum = l2.val + carry;
            carry = sum / 10;
            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            l2 = l2.next;
        }

        if (carry > 0)
            cur.next = new ListNode(carry);

        return head;
    }
}