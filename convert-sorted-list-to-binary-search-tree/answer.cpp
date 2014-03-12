
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void insertToBST(TreeNode *root, int val) {
        if (val <= root->val) {
            if (root->left == NULL)
                root->left = new TreeNode(val);
            else
                insertToBST(root->left, val);
        } else {
            if (root->right == NULL)
                root->right = new TreeNode(val);
            else
                insertToBST(root->right, val);
        }
    }

    void insertElements(vector<int> &num, int low, int high, TreeNode *root) {
        if (low > high)
            return;
        int mid = (low + high) >> 1;
        insertToBST(root, num[mid]);
        insertElements(num, low, mid - 1, root);
        insertElements(num, mid + 1, high, root);
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> num;
        while (head) {
            num.push_back(head->val);
            head = head->next;
        }
        int n = num.size();
        if (n == 0)
            return NULL;
        int mid = n >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        insertElements(num, 0, mid - 1, root);
        insertElements(num, mid + 1, n - 1, root);
        return root;
    }
};