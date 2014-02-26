
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeLinkNode *father, TreeLinkNode *son) {
        if (!son)
            return;
        // is left son
        if (father->left == son) {
            TreeLinkNode *current = father;
            while (current) {
                if (current->left && current->left != son) {
                    son->next = current->left;
                    break;
                }
                if (current->right) {
                    son->next = current->right;
                    break;
                }
                current = current->next;
            }
        }
        // is right son
        else {
            TreeLinkNode *current = father->next;
            while (current) {
                if (current->left) {
                    son->next = current->left;
                    break;
                }
                if (current->right) {
                    son->next = current->right;
                    break;
                }
                current = current->next;
            }
        }
        dfs(son, son->right);
        dfs(son, son->left);
    }

public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        dfs(root, root->right);
        dfs(root, root->left);
    }
};