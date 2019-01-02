/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define N 1
#define i64 long long
#define VI vector<int>
#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#define INT_MAX 0x7fffffff
const i64 MOD = 1000000000 + 7;

class Solution {
private:
    VI dfs(TreeNode* root) {
        // install(monitored), non-install(monitored), non-install(non-monitored) 
        if (root->left == nullptr && root->right == nullptr)
            return {1, INT_MAX, 0};
        else if (root->left == nullptr || root->right == nullptr) {
            VI child = (root->left != nullptr) ? dfs(root->left) : dfs(root->right);
            return {1 + *min_element(begin(child), end(child)), child[0], child[1]};
        }

        VI l = dfs(root->left);
        VI r = dfs(root->right);
        VI ans(3, INT_MAX);

        // install
        FOR(i, 0, 3) FOR(j, 0, 3) {
            if (l[i] != INT_MAX && r[j] != INT_MAX)
                ans[0] = min(ans[0], l[i] + r[j] + 1);
        }
        // non-install(monitored)
        FOR(i, 0, 2) FOR(j, 0, 2) {
            if (i == 1 && j == 1)
                continue;
            if (l[i] != INT_MAX && r[j] != INT_MAX)
                ans[1] = min(ans[1], l[i] + r[j]);
        }
        // non-install(non-monitored)
        if (l[1] != INT_MAX && r[1] != INT_MAX)
            ans[2] = min(ans[2], l[1] + r[1]);
        return ans;
    }

public:
    int minCameraCover(TreeNode* root) {
        VI ans = dfs(root);
        return *min_element(begin(ans), end(ans) - 1);
    }
};
