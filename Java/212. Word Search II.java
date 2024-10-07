import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = buildTrie(words);

        List<String> wordsOnBoard = new ArrayList<>();

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                searchOnBoard(board, root, wordsOnBoard, i, j);
            }
        }

        return wordsOnBoard;
    }

    private void searchOnBoard(char[][] board, TrieNode root, List<String> wordsOnBoard, int i, int j) {
        if (i < 0 || j < 0 || i == board.length || j == board[0].length)
            return;
        char c = board[i][j];

        if (c == '#' || root.characters[c - 'a'] == null)
            return;

        root = root.characters[c - 'a'];

        if (root.word != null) {
            wordsOnBoard.add(root.word);
            root.word = null;
        }

        board[i][j] = '#';
        searchOnBoard(board, root, wordsOnBoard, i + 1, j);
        searchOnBoard(board, root, wordsOnBoard, i - 1, j);
        searchOnBoard(board, root, wordsOnBoard, i, j + 1);
        searchOnBoard(board, root, wordsOnBoard, i, j - 1);
        board[i][j] = c;
    }

    private TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode cur = root;
            for (Character ch : word.toCharArray()) {
                if (cur.characters[ch - 'a'] == null)
                    cur.characters[ch - 'a'] = new TrieNode();
                cur = cur.characters[ch - 'a'];
            }
            cur.word = word;
        }
        return root;
    }

    public class TrieNode {
        TrieNode[] characters;
        String word;

        public TrieNode() {
            characters = new TrieNode[26];
            word = null;
        }
    }
}