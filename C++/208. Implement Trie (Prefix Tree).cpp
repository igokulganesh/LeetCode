struct Node
{
    vector<Node*> m ; 
    bool isEnd ; 

    Node()
    {
        m = vector<Node*>(26, nullptr); 
        isEnd = false ; 
    }
};


class Trie {

    Node* root ; 

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Node *cur = root ; 

        for(int i = 0 ; i < word.size() ; i++)
        {
            // check character present or not 
            if(cur->m[word[i]-'a'] == nullptr)
                cur->m[word[i]-'a'] = new Node(); 

            cur = cur->m[word[i]-'a'] ; // Move to next character ;  
        }
        cur->isEnd = true ;   
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Node *cur = root ; 

        for(int i = 0 ; i < word.size() ; i++)
        {
            if(cur->m[word[i]-'a'] == nullptr)
                return false ; 
            cur = cur->m[word[i]-'a'] ; 
        }   

        return cur->isEnd ;  
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) 
    {
        Node *cur = root ; 

        for(int i = 0 ; i < word.size() ; i++)
        {
            if(cur->m[word[i]-'a'] == nullptr)
                return false ; 
            cur = cur->m[word[i]-'a'] ; 
        }   

        return true ;   
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */