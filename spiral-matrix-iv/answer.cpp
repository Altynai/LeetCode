const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> spiralMatrix(int n, int m, ListNode *head) {
    vector<vector<int>> ans(n, vector<int>(m, -1));
    int x = 0, y = -1, k = 0;
    while (head != nullptr) {
      int nx = x + dx[k], ny = y + dy[k];
      if (!inside(n, m, nx, ny) or ans[nx][ny] != -1)
        k = (k + 1) % 4;
      else {
        ans[nx][ny] = head->val;
        head = head->next;
        x = nx, y = ny;
      }
    }
    return ans;
  }
};
