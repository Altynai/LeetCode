#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define N 26

struct Node {
    bool is_word;
    Node* son[N];

    Node() {
        is_word = false;
        memset(son, 0, sizeof(son));
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        int n = word.length();
        Node* p = root;
        for (int i = 0; i < n; ++i) {
            int pos = word[i] - 'a';
            if (p->son[pos] == NULL)
                p->son[pos] = new Node();
            p = p->son[pos];
        }
        p->is_word = true;
    }
};

class Solution {
public:

    Trie *trie;
    int n, m;
    vector<vector<char> >* board;
    vector<char> track;
    vector<vector<bool> > visited;
    vector<string> answer;

    Solution () {}

    void initBoard(vector<vector<char> >& board) {
        n = m = board.size();
        if (n == 0)
            return;
        m = board[0].size();
        this->board = &board;
        visited = vector<vector<bool> >(n);
        for (int i = 0; i < n; ++i)
            visited[i] = vector<bool>(m, false);
    }

    void resetVisited() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                visited[i][j] = false;
    }

    void initTrie(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); ++i)
            trie->insert(words[i]);
        track = vector<char>();
    }

    void dfs(Node* p, int x, int y, int deepth) {
        visited[x][y] = true;
        if (deepth >= track.size())
            track.push_back((*board)[x][y]);
        else
            track[deepth] = (*board)[x][y];
        if (p->is_word) {
            string word = string(track.begin(), track.begin() + deepth + 1);
            answer.push_back(word);
            p->is_word = false;
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
                continue;
            int pos = (*board)[nx][ny] - 'a';
            Node* np = p->son[pos];
            if (np != NULL)
                dfs(np, nx, ny, deepth + 1);
        }
        visited[x][y] = false;
    }

    vector<string> solve() {
        answer.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int pos = (*board)[i][j] - 'a';
                Node* p = trie->root->son[pos];
                if (p != NULL) {
                    resetVisited();
                    dfs(p, i, j, 0);
                }
            }
        }
        return answer;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        initBoard(board);
        if (n == 0)
            return vector<string>();
        initTrie(words);
        return solve();
    }
};