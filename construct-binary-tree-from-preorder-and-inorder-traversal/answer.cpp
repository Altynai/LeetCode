
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int findInorderIndex(vector<int> &inorder, int _low, int _high, int value) {
        for (int i = _low; i <= _high; i++) {
            if (inorder[i] == value)
                return i;
        }
    }

    TreeNode *dfs(vector<int> &preorder, int &low, int &high, vector<int> &inorder, int _low, int _high) {
        if (low > high || _low > _high)
            return NULL;
        TreeNode *root = new TreeNode(preorder[low]);
        int index = findInorderIndex(inorder, _low, _high, preorder[low]);
        root->left = dfs(preorder, ++low, high, inorder, _low, index - 1);
        root->right = dfs(preorder, low, high, inorder, index + 1, _high);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0)
            return NULL;
        int low = 0, high = n - 1;
        return dfs(preorder, low, high, inorder, 0, n - 1);
    }
};