/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode *root) {
        if (root == NULL)
            return;
        stk.push(root);
        while (root->left != NULL) {
            stk.push(root->left);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        TreeNode* current = top->right;
        if (current != NULL) {
            stk.push(current);
            while (current->left != NULL) {
                stk.push(current->left);
                current = current->left;
            }
        }
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */