
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
    vector<TreeNode *> dfs(int low, int high) {
        if (low > high) {
            vector<TreeNode *> result;
            result.push_back(NULL);
            return result;
        }
        // enumerate the root
        vector<TreeNode *> result;
        for (int root = low; root <= high; root++) {
            vector<TreeNode *> left_child_result = dfs(low, root - 1);
            vector<TreeNode *> right_child_result = dfs(root + 1, high);
            for (int i = 0; i < (int)left_child_result.size(); i++) {
                for (int j = 0; j < (int)right_child_result.size(); j++) {
                    TreeNode *root_node = new TreeNode(root);
                    root_node->left = left_child_result[i];
                    root_node->right = right_child_result[j];
                    result.push_back(root_node);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        return dfs(1, n);
    }
};
