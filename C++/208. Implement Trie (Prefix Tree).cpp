#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    vector<TrieNode *> map;
    bool is_end;

    TrieNode()
    {
        map = vector<TrieNode *>(26, nullptr);
        is_end = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *cur = root;
        for (char character : word)
        {
            character -= 'a';
            if (cur->map[character] == nullptr)
                cur->map[character] = new TrieNode();
            cur = cur->map[character]; // Move to next character
        }
        cur->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *cur = root;

        for (char character : word)
        {
            character -= 'a';
            if (cur->map[character] == nullptr)
                return false;
            cur = cur->map[character];
        }

        return cur->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *cur = root;

        for (char character : prefix)
        {
            character -= 'a';
            if (cur->map[character] == nullptr)
                return false;
            cur = cur->map[character];
        }

        return true;
    }
};
