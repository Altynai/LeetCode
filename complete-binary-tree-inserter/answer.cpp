/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> nodes;

public:
    CBTInserter(TreeNode* root) {
        nodes = {NULL};
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                root = q.front();
                q.pop();
                nodes.push_back(root);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        nodes.push_back(node);
        int n = nodes.size() - 1;
        TreeNode* parent = nodes[n / 2];
        if (n % 2 == 0)
            parent->left = node;
        else
            parent->right = node;
        return parent->val;
    }
    
    TreeNode* get_root() {
        int n = nodes.size();
        return (n == 1) ? NULL : nodes[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
