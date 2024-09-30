class Solution {
    private int pi = 0; // preorderIndex

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return construct(preorder, inorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] preorder, int[] inorder, int low, int high) {
        if (low > high)
            return null;

        TreeNode root = new TreeNode(preorder[pi++]);

        if (low == high)
            return root;

        int pos = findPosition(inorder, root.val);

        root.left = construct(preorder, inorder, low, pos - 1); // construct left
        root.right = construct(preorder, inorder, pos + 1, high); // construct right

        return root;
    }

    private int findPosition(int[] arr, int val) {
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == val)
                return i;

        return -1;
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