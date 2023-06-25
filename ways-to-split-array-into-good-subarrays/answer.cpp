const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfGoodSubarraySplits(vector<int> &a) {
    int n = a.size();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)
        pos.push_back(i);
    }

    int m = pos.size();
    if (m <= 1)
      return m;

    int ans = 1;
    for (int i = 1; i < m; i++) {
      int d = pos[i] - pos[i - 1];
      ans = 1LL * ans * d % MOD;
    }
    return ans;
  }
};
