class Trie {

    private final Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node cur = root;
        for (Character ch : word.toCharArray()) {
            if (cur.characters[ch - 'a'] == null)
                cur.characters[ch - 'a'] = new Node();
            cur = cur.characters[ch - 'a'];
        }
        cur.isWord = true;
    }

    public boolean search(String word) {
        Node cur = root;
        for (Character ch : word.toCharArray()) {
            if (cur.characters[ch - 'a'] == null)
                return false;
            cur = cur.characters[ch - 'a'];
        }
        return cur.isWord;
    }

    public boolean startsWith(String prefix) {
        Node cur = root;
        for (Character ch : prefix.toCharArray()) {
            if (cur.characters[ch - 'a'] == null)
                return false;
            cur = cur.characters[ch - 'a'];
        }
        return true;
    }

    public class Node {
        public Node[] characters;
        public boolean isWord;

        public Node() {
            characters = new Node[26];
            isWord = false;
        }
    }
}