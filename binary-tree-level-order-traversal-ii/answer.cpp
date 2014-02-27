
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
    int depthOfTree(TreeNode *root) {
        if (!root)
            return 0;
        int depth = std::max(depthOfTree(root->left), depthOfTree(root->right));
        return depth + 1;
    }

    void dfs(vector<vector<int> >& result, TreeNode* root, int depth){
    	if(!root)
    		return;
    	result[depth].push_back(root->val);
    	dfs(result, root->left, depth - 1);
    	dfs(result, root->right, depth - 1);
    }

public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int depth = depthOfTree(root);
        vector<vector<int> > result;
        for (int i = 0; i < depth; i++)
            result.push_back(vector<int>());
        dfs(result, root, depth - 1);
        return result;
    }
};