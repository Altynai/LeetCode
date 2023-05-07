class Solution {
public:
  vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
    vector<int> c(n, 0);
    vector<int> ans;
    int cnt = 0;
    for (auto q : queries) {
      int idx = q[0], color = q[1];
      if (idx > 0 and c[idx - 1] == c[idx] and c[idx] > 0)
        cnt--;
      if (idx + 1 < n and c[idx + 1] == c[idx] and c[idx] > 0)
        cnt--;
      c[idx] = color;
      if (idx > 0 and c[idx - 1] == c[idx] and c[idx] > 0)
        cnt++;
      if (idx + 1 < n and c[idx + 1] == c[idx] and c[idx] > 0)
        cnt++;
      ans.push_back(cnt);
    }
    return ans;
  }
};
