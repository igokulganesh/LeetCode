
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();

        if (root == null)
            return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            int level = queue.size();
            Double sum = 0.0;

            while (level-- > 0) {
                root = queue.poll();
                sum += root.val;

                if (root.left != null)
                    queue.add(root.left);

                if (root.right != null)
                    queue.add(root.right);
            }

            result.add((double) sum / size);
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