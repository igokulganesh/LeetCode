
import java.util.LinkedList;
import java.util.Queue;

class BSTIterator {

    Queue<Integer> queue;

    public BSTIterator(TreeNode root) {
        queue = new LinkedList<>();
        inorderTraversal(root);
    }

    private void inorderTraversal(TreeNode root) {
        if (root != null) {
            inorderTraversal(root.left);
            queue.add(root.val);
            inorderTraversal(root.right);
        }
    }

    public int next() {
        return queue.poll();
    }

    public boolean hasNext() {
        return !queue.isEmpty();
    }

    /* ignore-boiler-code */
    public class TreeNode {
        public int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode() {
        }

        public TreeNode(int val) {
            this.val = val;
        }

        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}