
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        if (root == null)
            return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        Boolean reverse = false;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> levels = new ArrayList<>(size);

            while (size-- > 0) {
                root = queue.poll();
                levels.add(root.val);

                if (root.left != null)
                    queue.add(root.left);

                if (root.right != null)
                    queue.add(root.right);
            }

            if (reverse)
                result.add(levels.reversed());
            else
                result.add(levels);
            reverse = !reverse;
        }

        return result;
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