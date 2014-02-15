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
    void depthFirstSearch(vector<vector<int> > &result, TreeNode *root, int i, int storage[], int current_sum, int sum) {
        if (root == NULL)
            return;
        storage[i] = root->val;
        current_sum += root->val;
        if (isLeaf(root)) {
            if (current_sum == sum)
                result.push_back(vector<int>(storage, storage + i + 1));
            return;
        }
        depthFirstSearch(result, root->left, i + 1, storage, current_sum, sum);
        depthFirstSearch(result, root->right, i + 1, storage, current_sum, sum);
    }

    bool isLeaf(TreeNode *root) {
        return root->left == NULL && root->right == NULL;
    }

    int findMaxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        return std::max(findMaxDepth(root->left), findMaxDepth(root->right)) + 1;
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        int n = findMaxDepth(root);
        int *storage = new int[n];
        depthFirstSearch(result, root, 0, storage, 0, sum);
        return result;
    }
};