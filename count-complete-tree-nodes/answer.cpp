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
    int rightDepth(TreeNode* root) {
        int depth = 1;
        while (root->right != NULL) {
            depth++;
            root = root->right;
        }
        return depth;
    }

    int leftDepth(TreeNode* root) {
        int depth = 1;
        while (root->left != NULL) {
            depth++;
            root = root->left;
        }
        return depth;
    }

    bool exists(TreeNode* root, int binary_pos, int id) {
        for (int i = binary_pos; i >= 0; i--) {
            if (id & (1 << i))
                root = root->right;
            else
                root = root->left;
            if (root == NULL)
                return false;
        }
        return true;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l_depth = leftDepth(root), r_depth = rightDepth(root);
        if (l_depth == r_depth)
            return (1 << l_depth) - 1;
        assert(l_depth == r_depth + 1);
        int low = (1 << r_depth), high = (1 << l_depth) - 1;
        int mid = 0, answer = 0;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (exists(root, l_depth - 2, mid)) {
                low = mid + 1;
                answer = mid;
            } else
                high = mid - 1;
        }
        return answer;
    }
};