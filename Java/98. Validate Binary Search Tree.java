import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean isValidBST(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        inorder(root, values);

        for (int i = 0; i < values.size() - 1; i++) {
            if (values.get(i) >= values.get(i + 1))
                return false;
        }

        return true;
    }

    private void inorder(TreeNode root, List<Integer> values) {
        if (root != null) {
            inorder(root.left, values);
            values.add(root.val);
            inorder(root.right, values);
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