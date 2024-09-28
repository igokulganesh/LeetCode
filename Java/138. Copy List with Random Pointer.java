
import java.util.HashMap;
import java.util.Map;

class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> map = new HashMap<>();

        for (Node cur = head; cur != null; cur = cur.next)
            map.put(cur, new Node(cur.val));

        Node clone;
        for (Node cur = head; cur != null; cur = cur.next) {
            clone = map.get(cur);
            clone.next = map.getOrDefault(cur.next, null);
            clone.random = map.getOrDefault(cur.random, null);
        }

        return map.getOrDefault(head, null);
    }

    public class Node {
        public int val;
        public Node next;
        public Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }
}