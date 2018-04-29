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
    
    bool isLeaf() {
        for (int i = 0; i < N; ++i) {
            if (son[i] != NULL)
                return false;
        }
        return true;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        lenSum = count = 0;
    }

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

    void dfs(TrieNode* root, int len) {
        if (root->isLeaf()) {
            lenSum += len;
            count++;
        }
        for (int i = 0; i < N; ++i) {
            if (root->son[i] != NULL)
                dfs(root->son[i], len + 1);
        }
    }

    int solve() {
        dfs(root, 0);
        return lenSum + count;
    }

private:
    TrieNode* root;
    int lenSum, count;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto word : words) {
            reverse(word.begin(), word.end());
            trie->insert(word);
        }
        return trie->solve();
    }
};