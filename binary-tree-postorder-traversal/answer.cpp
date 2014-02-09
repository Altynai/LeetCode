
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> result;
    	traversal(root, result);
    	return result;
    }

private:
    void traversal(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        traversal(root->left, result);
        traversal(root->right, result);
        result.push_back(root->val);
    }
};