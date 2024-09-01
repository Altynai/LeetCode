class Solution {
public:
  vector<int> resultsArray(vector<vector<int>> &queries, int k) {
    int n = queries.size();
    vector<int> ans(n, -1);
    priority_queue<int> que;
    for (int i = 0; i < n; i++) {
      que.push(abs(queries[i][0]) + abs(queries[i][1]));
      while (que.size() > k)
        que.pop();
      if (que.size() == k)
        ans[i] = que.top();
    }
    return ans;
  }
};
