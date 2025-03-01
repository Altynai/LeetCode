using int64 = long long;

class Solution {
public:
  long long maxSum(vector<vector<int>> &a, vector<int> &limits, int k) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++)
      sort(a[i].rbegin(), a[i].rend());

    // element value, row, index
    priority_queue<array<int, 3>> que;
    for (int i = 0; i < n; i++) {
      if (limits[i] > 0) {
        que.push({a[i][0], i, 0});
      }
    }

    int64 ans = 0;
    while (k--) {
      auto [val, row, idx] = que.top();
      que.pop();

      ans += val;
      if (idx + 1 < limits[row]) {
        que.push({a[row][idx + 1], row, idx + 1});
      }
    }
    return ans;
  }
};
