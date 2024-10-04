import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null)
            return null;

        HashMap<Node, Node> map = new HashMap<>();
        map.put(node, new Node(node.val));

        Queue<Node> queue = new LinkedList<>();
        queue.add(node);

        Node org, copy;

        while (!queue.isEmpty()) {
            org = queue.poll();
            copy = map.get(org);

            for (Node neighbor : org.neighbors) {
                if (!map.containsKey(neighbor)) {
                    map.put(neighbor, new Node(neighbor.val));
                    queue.add(neighbor);
                }
                copy.neighbors.add(map.get(neighbor));
            }
        }

        return map.get(node);
    }

    class Node {
        public int val;
        public List<Node> neighbors;

        public Node() {
            val = 0;
            neighbors = new ArrayList<>();
        }

        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<>();
        }

        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }
}