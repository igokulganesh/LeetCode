class Solution {
    int sum = 0;

    public int sumNumbers(TreeNode root) {
        sumNumbers(root, 0);
        return sum;
    }

    public void sumNumbers(TreeNode root, int cur) {
        if (root == null)
            return;

        cur = (cur * 10) + root.val;

        if (root.left == null && root.right == null)
            sum += cur;
        else {
            sumNumbers(root.left, cur);
            sumNumbers(root.right, cur);
        }
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