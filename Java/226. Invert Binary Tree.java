class Solution {

    public TreeNode invertTree(TreeNode root) {
        if (root != null)
            mirror(root);
        return root;
    }

    private void mirror(TreeNode root) {
        if (root != null) {
            // Swap
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;

            mirror(root.left);
            mirror(root.right);
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