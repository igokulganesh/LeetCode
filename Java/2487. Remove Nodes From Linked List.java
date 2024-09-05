import java.util.Stack;

class Solution {

    class ListNode {
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

    public ListNode removeNodes(ListNode head) {
        Stack<ListNode> stack = new Stack<>();

        ListNode temp = head;

        while (temp != null) {
            stack.add(temp);
            temp = temp.next;
        }

        int right_max = Integer.MIN_VALUE;

        while (!stack.isEmpty()) {
            temp = stack.pop();

            // remove if right max
            if (temp.val < right_max) {
                if (stack.isEmpty())
                    head = temp.next;
                else
                    stack.peek().next = temp.next;
                temp.next = null;
            } else
                right_max = temp.val;
        }

        return head;
    }
}
