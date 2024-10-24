import java.util.HashMap;
import java.util.Map;

class LRUCache {

    private int capacity;
    private Map<Integer, Node> map;
    private List list;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.list = new List();
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            list.moveFront(node);
            return node.value;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;
            list.moveFront(node);
        } else {
            if (list.size == capacity) {
                map.remove(list.getBack().key);
                list.popBack();
            }
            Node node = new Node(key, value);
            list.pushFront(node);
            map.put(key, node);
        }
    }

    public class List {
        private Node head;
        private Node tail;
        public int size;

        public List() {
            head = new Node();
            tail = new Node();
            size = 0;

            head.next = tail;
            tail.prev = head;
        }

        public void pushFront(Node node) {
            Node curFirst = head.next;

            node.prev = head;
            node.next = curFirst;

            head.next = node;
            curFirst.prev = node;

            size++;
        }

        public void moveFront(Node node) {
            // Remove Cur position
            remove(node);

            // Move to Front
            pushFront(node);
        }

        public void popBack() {
            remove(tail.prev);
        }

        public Node getBack() {
            return tail.prev;
        }

        public void remove(Node node) {
            Node prev = node.prev;
            Node next = node.next;

            prev.next = next;
            next.prev = prev;
            size--;
        }
    }

    public class Node {
        public int key;
        public int value;
        public Node next;
        public Node prev;

        public Node() {
            this.key = -1;
            this.value = -1;
            this.next = null;
            this.prev = null;
        }

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.next = null;
            this.prev = null;
        }
    }
}
