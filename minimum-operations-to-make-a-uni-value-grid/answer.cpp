class Solution {
public:
  int minOperations(vector<vector<int>> &a, int x) {
    vector<int> b;
    for (auto &row : a)
      for (int val : row)
        b.push_back(val);
    sort(b.begin(), b.end());
    int m = b[b.size() / 2];

    int ans = 0;
    for (auto &row : a) {
      for (int val : row) {
        int d = abs(val - m);
        if (d % x != 0)
          return -1;
        ans += d / x;
      }
    }
    return ans;
  }
};
