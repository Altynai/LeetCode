/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Node {
    int size, fix, count;
    int value;
    Node* left, *right;
    Node(int _value): value(_value) {
        count = size = 1;
        fix = std::rand();
        left = right = NULL;
    }

    inline int lsize() {
        return left ? left->size : 0;
    }
    inline int rsize() {
        return right ? right->size : 0;
    }
};

class Treap {
private:
    void rotateLeft(Node* &p) {
        Node* son = p->right;
        int x = p->lsize(), y = son->lsize(), z = son->rsize();
        p->right = son->left;
        son->left = p;
        p->size = x + y + p->count;
        son->size = p->size + z + son->count;
        p = son;
    }

    void rotateRight(Node* &p) {
        Node* son = p->left;
        int x = son->lsize(), y = son->rsize(), z = p->rsize();
        p->left = son->right;
        son->right = p;
        p->size = y + z + p->count;
        son->size = x + p->size + son->count;
        p = son;
    }

    void insert(Node* &p, int value) {
        if (p == NULL)
            p = new Node(value);
        else if (value == p->value) {
            p->size++;
            p->count++;
        } else if (value < p->value) {
            insert(p->left, value);
            if (p->left->fix < p->fix)
                rotateRight(p);
        } else {
            insert(p->right, value);
            if (p->right->fix < p->fix)
                rotateLeft(p);
        }
        p->size = p->lsize() + p->rsize() + p->count;
    }

public:
    Node* root;

    Treap(): root(NULL) {
        std::srand(std::time(0));
    }

    void insert(int value) {
        insert(root, value);
    }
};

class SummaryRanges {
private:
    Treap* treap;

    void dfs(Node* root, vector<Interval>& answer) {
        if (root == NULL)
            return;
        dfs(root->left, answer);
        int value = root->value, n = answer.size();
        if (n == 0 || value > answer[n - 1].end + 1)
            answer.push_back(Interval(value, value));
        else
            answer[n - 1].end = max(answer[n - 1].end, value);
        dfs(root->right, answer);
    }

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        treap = new Treap();
    }

    void addNum(int val) {
        treap->insert(val);
    }

    vector<Interval> getIntervals() {
        if (treap->root == NULL)
            return vector<Interval>();
        vector<Interval> answer;
        dfs(treap->root, answer);
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */