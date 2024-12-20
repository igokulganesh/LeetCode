import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    /*
     * DFS
     */
    public TreeNode reverseOddLevels_1(TreeNode root) {
        reverseOddLevels(root.left, root.right, true);
        return root;
    }

    public void reverseOddLevels(TreeNode left, TreeNode right, boolean isOdd) {
        if (left == null || right == null)
            return;

        if (isOdd) {
            int temp = left.val;
            left.val = right.val;
            right.val = temp;
        }

        isOdd = !isOdd;
        reverseOddLevels(left.left, right.right, isOdd);
        reverseOddLevels(left.right, right.left, isOdd);
    }

    /*
     * BFS
     */
    public TreeNode reverseOddLevels(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        boolean isOdd = false;

        while (!que.isEmpty()) {
            int size = que.size();
            List<TreeNode> nodes = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = que.poll();
                nodes.add(node);

                if (node.left != null)
                    que.add(node.left);

                if (node.right != null)
                    que.add(node.right);

            }

            if (isOdd) {
                int l = 0, r = nodes.size() - 1;
                while (l < r) {
                    int temp = nodes.get(l).val;
                    nodes.get(l).val = nodes.get(r).val;
                    nodes.get(r).val = temp;
                    l++;
                    r--;
                }
            }
            isOdd = !isOdd;
        }

        return root;
    }

    /* ignore boiler code */
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
    }
}