/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define N 1001

class Solution {
private:
    bool graph[N][N];
    int dis[N];

    void init() {
        memset(graph, 0, sizeof(graph));
        memset(dis, -1, sizeof(dis));
    }

    void build(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* left = root->left;
        if (left) {
            graph[root->val][left->val] = true;
            graph[left->val][root->val] = true;
            build(left);
        }
        TreeNode* right = root->right;
        if (right) {
            graph[root->val][right->val] = true;
            graph[right->val][root->val] = true;
            build(right);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        init();
        build(root);
        queue<int> q;
        dis[target->val] = 0;
        q.push(target->val);
        vector<int> ans;
        while (!q.empty()) {
            int ft = q.front();
            q.pop();
            for (int i = 0; i < N; i++) {
                if (graph[ft][i] && dis[i] == -1) {
                    dis[i] = dis[ft] + 1;
                    q.push(i);
                    if (dis[i] == K)
                        ans.push_back(i);
                }
            }
        }
        if (K == 0)
            ans.push_back(target->val);
        return ans;
    }
};
