#define N 1
#define i64 long long
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define SZ(a) (a).size()
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)
#define DFOR(i, s, t) for (int i = (s); i > (t); i--)
#define FILL(a, b) memset(a, b, sizeof(a))
#define PRINTVEC(v) std::copy(begin((v)), end((v)),std::ostream_iterator<int>(std::cout, " " )), cout << endl;
#define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
const i64 MOD = 1000000000 + 7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans;
    
    VI dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return {1, root->val};
        
        int cnt = 1, val = root->val;
        vector<TreeNode*> children = {root->left, root->right};
        FOR(i, 0, 2) {
            if (children[i] != nullptr) {
                VI got = dfs(children[i]);
                ans += abs(got[0] - got[1]);
                cnt += got[0];
                val += got[1];
            }
        }
        return {cnt, val};
    }

public:
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
