class Solution {
public:
  vector<int> answerQueries(vector<int> &a, vector<int> &q) {
    int n = a.size(), m = q.size();
    sort(a.begin(), a.end());

    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
      int j = 0, sum = 0;
      while (j < n and sum + a[j] <= q[i])
        sum += a[j++];
      ans[i] = j;
    }
    return ans;
  }
};
