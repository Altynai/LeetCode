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
    int deepest, cnt;
    int deepest2;
    TreeNode* ans;

    void dfs(TreeNode* cur, int depth) {
        TreeNode *left = cur->left, *right = cur->right;
        if (left == NULL && right == NULL) {
            if (depth == deepest)
                cnt++;
            else if (depth > deepest) {
                deepest = depth;
                cnt = 1;
            }
            return;
        }
        if (left != NULL)
            dfs(left, depth + 1);
        if (right != NULL)
            dfs(right, depth + 1);
    }

    int dfs2(TreeNode* cur, int depth){
        TreeNode *left = cur->left, *right = cur->right;
        int n = 0;
        if (left == NULL && right == NULL)
            n = (depth == deepest) ? 1 : 0;
        else {
            if (left != NULL)
                n += dfs2(left, depth + 1);
            if (right != NULL)
                n += dfs2(right, depth + 1);
        }
        if (n == cnt && depth > deepest2) {
            ans = cur;
            deepest2 = depth;
        }
        return n;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL)
            return root;

        deepest = -1;
        cnt = 0;
        dfs(root, 0);

        deepest2 = -1;
        ans = NULL;
        dfs2(root, 0);
        return ans;
    }
};
