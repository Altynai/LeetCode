
struct Node {
    static const int N = 26;
    
    bool isword;
    Node *child[N];
    Node() {
        isword = false;
        for (int i = 0; i < N; i++)
            child[i] = NULL;
    }
};

class Trie {
private:
    void insertWord(const string &word) {
        int n = word.size();
        Node *current = root;
        for (int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if (current->child[index] == NULL)
                current->child[index] = new Node();
            current = current->child[index];
        }
        current->isword = true;
    }

public:
    Node *root;
    Trie(unordered_set<string> &dict) {
        root = new Node();
        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++)
            insertWord(*i);
    }

};


class Solution {
private:
    Trie *trie;

    bool dfs(string &s, int index) {
        int length = s.size();
        if (index == length)
            return true;
        Node *current = trie->root;
        for (int j = index; j < length; j++) {
            int pos = s[j] - 'a';
            if (current->child[pos] == NULL)
                return false;
            if (dfs(s, j + 1))
                return true;
            current = current->child[pos];
        }
        return false;
    }

public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        trie = new Trie(dict);
        return dfs(s, 0);
    }
};