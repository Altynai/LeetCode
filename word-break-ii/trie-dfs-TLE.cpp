
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
    string makeString(string &s, vector<int> &separator, int n) {
        int low = 0, high = 0;
        string result = "";
        for (int i = 0; i < n; i++) {
            high = separator[i];
            result += s.substr(low, high - low + 1);
            low = high + 1;
            if (i)
                result.push_back(' ');
        }
        return result;
    }

    void dfs(vector<string> &result, string &s, int index, vector<int> &separator, int n) {
        int length = s.size();
        if (index == length) {
            result.push_back(makeString(s, separator, n));
            return;
        }
        Node *current = trie->root;
        for (int j = index; j < length; j++) {
            int pos = s[j] - 'a';
            if (current->child[pos] == NULL)
                break;
            current = current->child[pos];
            if (current->isword) {
                separator[n] = j;
                dfs(result, s, j + 1, separator, n + 1);
            }
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        trie = new Trie(dict);
        int n = s.size();
        vector<int> separator(n + 1, 0);
        dfs(result, s, 0, separator, 0);
        return result;
    }
};
