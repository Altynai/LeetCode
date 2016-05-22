#define N 26

class TrieNode {
public:
    TrieNode* son[N];
    bool isWord;

    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < N; ++i)
            son[i] = NULL;
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++i) {
            int offset = word[i] - 'a';
            if (node->son[offset] == NULL)
                node->son[offset] = new TrieNode();
            node = node->son[offset];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++i) {
            int offset = word[i] - 'a';
            if (node->son[offset] == NULL)
                return false;
            node = node->son[offset];
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int offset = prefix[i] - 'a';
            if (node->son[offset] == NULL)
                return false;
            node = node->son[offset];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");