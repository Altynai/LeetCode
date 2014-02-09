#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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