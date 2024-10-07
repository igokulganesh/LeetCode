class WordDictionary {

    private final TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void addWord(String word) {
        TrieNode cur = root;
        for (Character ch : word.toCharArray()) {
            if (cur.characters[ch - 'a'] == null)
                cur.characters[ch - 'a'] = new TrieNode();
            cur = cur.characters[ch - 'a'];
        }
        cur.isEnd = true;
    }

    public boolean search(String word) {
        return search(root, word, 0);
    }

    private boolean search(TrieNode cur, String word, int i) {
        if (word.length() == i)
            return cur.isEnd;

        if (word.charAt(i) == '.') {
            for (int k = 0; k < 26; k++) {
                if (cur.characters[k] != null && search(cur.characters[k], word, i + 1))
                    return true;
            }
        } else if (cur.characters[word.charAt(i) - 'a'] != null) {
            cur = cur.characters[word.charAt(i) - 'a'];
            return search(cur, word, i + 1);
        }
        return false;
    }

    public class TrieNode {
        public TrieNode characters[];
        public boolean isEnd;

        public TrieNode() {
            characters = new TrieNode[26];
            isEnd = false;
        }
    }
}