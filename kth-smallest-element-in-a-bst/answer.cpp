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
    int search(TreeNode* root, int k, int& answer) {
        if (root == NULL)
            return 0;
        int size = search(root->left, k, answer);
        if (k <= size)
            return size + 1;
        else if (k == size + 1) {
            answer = root->val;
            return size + 1;
        } else
            return size + 1 + this->search(root->right, k - size - 1, answer);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int answer = 0;
        this->search(root, k, answer);
        return answer;
    }
};