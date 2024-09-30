class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root.left, root.right);
    }

    private boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null)
            return true;

        if (left == null || right == null || left.val != right.val)
            return false;

        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
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