
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public Node connect(Node root) {
        if (root == null)
            return root;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        int level;
        Node cur;

        while (!queue.isEmpty()) {
            level = queue.size();

            while (level-- > 0) {
                cur = queue.poll();

                if (cur.left != null)
                    queue.add(cur.left);

                if (cur.right != null)
                    queue.add(cur.right);

                if (level > 0)
                    cur.next = queue.peek();
                else
                    cur.next = null;
            }
        }

        return root;
    }

    /* Ignore Boiler Code */
    class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }
}