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
const i64 MOD = 1000000000 + 7;

class Solution {
private:
    VI ans;
    
    bool dfs(TreeNode* root, VI& voyage, int l, int r) {
        if (voyage[l] != root->val)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return l + 1 == r;
        else if (root->left == nullptr || root->right == nullptr) {
            TreeNode* child = (root->left == nullptr) ? root->right : root->left;
            return dfs(child, voyage, l + 1, r);
        } else {
            VI where;
            FOR(i, l + 1, r) {
                if (voyage[i] == root->left->val || voyage[i] == root->right->val)
                    where.push_back(i);
            }
            if (where.size() != 2)
                return false;

            sort(begin(where), end(where));
            int a = where[0], b = where[1];
            if (a != l + 1)
                return false;
            else if (voyage[a] == root->right->val) {
                ans.push_back(root->val);
                return dfs(root->left, voyage, b, r) && dfs(root->right, voyage, a, b);
            } else {
                return dfs(root->left, voyage, a, b) && dfs(root->right, voyage, b, r);
            }
        }
    }

public:
    VI flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ans.clear();
        if (dfs(root, voyage, 0, voyage.size()))
            return ans;
        return {-1};
    }
};
