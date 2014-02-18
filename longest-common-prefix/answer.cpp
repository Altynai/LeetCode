
class Trie {
private:
    static const int N = 26;
    struct Node {
        int count;
        Node *child[N];
        Node() {
            count = 0;
            for (int i = 0; i < N; ++i)
                child[i] = NULL;
        }
    };
    Node *root;

    void insert(Node *root, const string &s, int i) {
        if (i == s.size())
            return;
        int index = s[i] - 'a';
        if (root->child[index] == NULL)
            root->child[index] = new Node();
        root->child[index]->count += 1;
        insert(root->child[index], s, i + 1);
    }

    bool hasOnlyOneChild(Node *root) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (root->child[i] != NULL)
                count++;
        }
        return count == 1;
    }

    bool same(Node* root, Node* child){
    	return root->count == 0 || (root->count && child->count == root->count);
    }

public:
    Trie(vector<string> strs) {
        root = new Node();
        for (int i = 0; i < strs.size(); i++)
            insert(root, strs[i], 0);
    };

    string longestCommonPrefix() {
        string s = "";
        while (hasOnlyOneChild(root)) {
            for (int i = 0; i < N; i++) {
                if (root->child[i] == NULL)
                    continue;
                if (!same(root, root->child[i]))
                    return s;
                s.push_back('a' + i);
                root = root->child[i];
                break;
            }
        }
        return s;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "")
                return "";
        }
        Trie *trie = new Trie(strs);
        return trie->longestCommonPrefix();
    }
};
