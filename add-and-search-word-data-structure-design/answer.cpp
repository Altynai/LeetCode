#include <cstdio>
#include <string>
using namespace std;

#define N 26

class Node {
public:
    Node* son[N];
    bool isWord;

    // Initialize your data structure here.
    Node() {
        for (int i = 0; i < N; ++i)
            son[i] = NULL;
        isWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); ++i) {
            int offset = word[i] - 'a';
            if (node->son[offset] == NULL)
                node->son[offset] = new Node();
            node = node->son[offset];
        }
        node->isWord = true;
    }
};


class WordDictionary {
private:
    bool search(Node* node, string& word, int pos) {
        if (node == NULL)
            return false;
        if (pos == word.length())
            return node->isWord;
        if (word[pos] == '.') {
            for (int offset = 0; offset < N; ++offset) {
                if (search(node->son[offset], word, pos + 1))
                    return true;
            }
        } else {
            int offset = word[pos] - 'a';
            if (search(node->son[offset], word, pos + 1))
                return true;
        }
        return false;
    }

public:
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        trie->insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(trie->root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char const *argv[]) {
    WordDictionary* dict = new WordDictionary();
    dict->addWord("bad");
    dict->addWord("dad");
    dict->addWord("mad");
    printf("%d\n", dict->search("pad"));
    printf("%d\n", dict->search("bad"));
    printf("%d\n", dict->search(".ad"));
    printf("%d\n", dict->search("b.."));
    return 0;
}