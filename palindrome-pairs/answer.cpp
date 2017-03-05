#define N 26

struct Node {
    Node* children[N];
    int index;

    Node() {
        for (int i = 0; i < N; ++i)
            children[i] = NULL;
        index = -1;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& word, int index) {
        Node* u = root;
        for (int i = 0; i < word.size(); ++i) {
            int offset = (int)(word[i] - 'a');
            if (u->children[offset] == NULL)
                u->children[offset] = new Node();
            u = u->children[offset];
        }
        u->index = index;
    }

    int find(const string& word, int start, int end) {
        Node* u = root;
        int step = (start <= end) ? 1 : -1;
        for (int i = start; i != end; i += step) {
            int offset = (int)(word[i] - 'a');
            if (u->children[offset] == NULL)
                return -1;
            u = u->children[offset];
        }
        return u->index;
    }
};

class Solution {
public:

    bool isPalindrome(const string& word, int start, int end) {
        for (int i = start, j = end - 1; i <= j; ++i, j--) {
            if (word[i] != word[j])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            string replace = words[i];
            reverse(replace.begin(), replace.end());
            trie->insert(replace, i);
        }
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == "") {
                for (int j = 0; j < words.size(); ++j) {
                    if (j != i && isPalindrome(words[j], 0, words[j].size())) {
                        ans.push_back({i, j});
                    }
                }
                continue;
            }
            for (int j = 0; j < words[i].size(); ++j) {
                // string left = words[i].substr(0, j);
                // string right = words[i].substr(j, words[i].size() - j);

                // left + right + left
                if (isPalindrome(words[i], j, words[i].size())) {
                    int index = trie->find(words[i], 0, j);
                    if (index != i && index != -1)
                        ans.push_back({i, index});
                }
                // right + left + right
                if (isPalindrome(words[i], 0, j)) {
                    int index = trie->find(words[i], j, words[i].size());
                    if (index != i && index != -1)
                        ans.push_back({index, i});
                }
            }
        }
        return ans;
    }
};