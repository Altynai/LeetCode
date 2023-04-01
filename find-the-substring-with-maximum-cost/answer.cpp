const int N = 26;

class Solution {
public:
  int maximumCostSubstring(string s, string chars, vector<int> &vals) {
    vector<int> cost(N);
    for (int i = 0; i < N; i++)
      cost[i] = i + 1;

    int m = chars.size();
    for (int i = 0; i < m; i++)
      cost[chars[i] - 'a'] = vals[i];

    int ans = 0, minv = 0, sum = 0;
    for (char c : s) {
      sum += cost[c - 'a'];
      ans = max(ans, sum - minv);
      minv = min(sum, minv);
    }
    return ans;
  }
};
