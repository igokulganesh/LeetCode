
import java.util.HashMap;
import java.util.Map;

class Solution {

    Map<Integer, Integer> inorderMap = new HashMap<>();
    int pi; // Postorder Index

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        pi = postorder.length - 1;

        for (int i = 0; i < inorder.length; i++)
            inorderMap.put(inorder[i], i);

        return construct(inorder, postorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] inorder, int[] postorder, int low, int high) {
        if (low > high)
            return null;

        TreeNode root = new TreeNode(postorder[pi--]);

        if (low == high)
            return root;

        int pos = inorderMap.get(root.val);

        root.right = construct(inorder, postorder, pos + 1, high);
        root.left = construct(inorder, postorder, low, pos - 1);

        return root;
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