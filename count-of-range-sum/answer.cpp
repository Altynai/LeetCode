#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <sstream>

using namespace std;

#define i64 long long

struct Node {
    int size, fix, count;
    i64 value;
    Node* left, *right;
    Node(i64 _value): value(_value) {
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
    Node* root;

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

    void insert(Node* &p, i64 value) {
        if (p == NULL)
            p = new Node(value);
        else if (value == p->value) {
            p->size++;
            p->count++;
        }
        else if (value < p->value) {
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

    int countNotGreaterThan(Node* &p, i64 value) {
        if (p == NULL)
            return 0;
        if (value == p->value)
            return p->lsize() + p->count;
        else if (value < p->value)
            return countNotGreaterThan(p->left, value);
        else
            return p->lsize() + p->count + countNotGreaterThan(p->right, value);
    }

public:
    Treap(): root(NULL) {
        std::srand(std::time(0));
    }

    void insert(i64 value) {
        insert(root, value);
    }

    int countNotGreaterThan(i64 value) {
        return countNotGreaterThan(root, value);
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0)
            return 0;
        // s[i] = sum(num[0] + ... + num[i - 1])
        vector<i64> s(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + nums[i - 1];
        Treap* tp = new Treap();
        int answer = 0;
        for (int i = n; i >= 0; --i) {
            int diff = tp->countNotGreaterThan(s[i] + upper) - \
                       tp->countNotGreaterThan(s[i] + lower - 1);
            answer += diff;
            tp->insert(s[i]);
        }
        return answer;
    }
};

int solve(const string& line, int lower, int upper) {
    string buf;
    stringstream ss(line);
    vector<int> nums;
    while (ss >> buf)
        nums.push_back(std::stoi(buf));
    Solution* s = new Solution();
    return s->countRangeSum(nums, lower, upper);
}

int main(int argc, char const *argv[]) {
    assert(5 == solve("-2 0 -2 -3 2 2 1 -3 4", 4, 11));
    assert(3 == solve("-2 5 -1", -2, 2));
    assert(3 == solve("0 0", 0, 0));
    assert(2 == solve("0 -3 -3 1 1 2", 3, 5));
    assert(3 == solve("-2147483647 0 -2147483647 2147483647", -564, 3864));
    return 0;
}