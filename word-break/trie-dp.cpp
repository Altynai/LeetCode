
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
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        s.insert(s.begin(), ' '); // make index start from 1
        Trie *trie = new Trie(dict);
        bool *dp = new bool[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = false;
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            if (!dp[i - 1])
                continue;
            Node *current = trie->root;
            int j = i;
            int pos = s[j] - 'a';
            while (current->child[pos] != NULL) {
                if (current->child[pos]->isword)
                    dp[j] = true;
                current = current->child[pos];
                if (++j > n)
                    break;
                pos = s[j] - 'a';
            }
        }
        return dp[n];
    }
};