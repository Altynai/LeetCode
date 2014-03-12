
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

    TreeNode *dfs(vector<int> &postorder, int &low, int &high, vector<int> &inorder, int _low, int _high) {
        if (low > high || _low > _high)
            return NULL;
        TreeNode *root = new TreeNode(postorder[high]);
        int index = findInorderIndex(inorder, _low, _high, postorder[high]);
        root->right = dfs(postorder, low, --high, inorder, index + 1, _high);
        root->left = dfs(postorder, low, high, inorder, _low, index - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = postorder.size();
        if (n == 0)
            return NULL;
        int low = 0, high = n - 1;
        return dfs(postorder, low, high, inorder, 0, n - 1);
    }
};