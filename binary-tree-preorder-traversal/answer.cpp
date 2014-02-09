
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> result;
    	traversal(root, result);
    	return result;
    }

private:
    void traversal(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }
};