
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
    string makeString(string &s, vector<int> &separator, int n) {
        int low = 1, high = 0;
        string result = "";
        for (int i = 0; i < n; i++) {
            if (i)
                result.push_back(' ');
            high = separator[i];
            result += s.substr(low, high - low + 1);
            low = high + 1;
        }
        return result;
    }

    void dfs(vector<string> &result, vector<vector<int> > &path, int index, string &s, vector<int> &separator, int n) {
        if (index >= s.size() - 1) {
            result.push_back(makeString(s, separator, n));
            return;
        }
        for (int i = 0; i < (int)path[index].size(); i++) {
            int next = path[index][i];
            separator[n] = next;
            dfs(result, path, next, s, separator, n + 1);
        }
    }

public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // init
        Trie *trie = new Trie(dict);
        int n = s.size();
        s.insert(s.begin(), ' '); // make index start from 1
        bool *dp = new bool[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = false;
        dp[0] = true;
        vector<vector<int> > path(n + 1, vector<int>());
        // find path
        for (int i = 1; i <= n; i++) {
            if (!dp[i - 1])
                continue;
            Node *current = trie->root;
            int j = i;
            int pos = s[j] - 'a';
            while (current->child[pos] != NULL) {
                if (current->child[pos]->isword) {
                    path[i - 1].push_back(j);
                    dp[j] = true;
                }
                current = current->child[pos];
                if (++j > n)
                    break;
                pos = s[j] - 'a';
            }
        }
        // dfs for get result from `path`
        vector<string> result;
        vector<int> separator(n + 2, 0);
        if (dp[n])
            dfs(result, path, 0, s, separator, 0);
        return result;
    }
};
