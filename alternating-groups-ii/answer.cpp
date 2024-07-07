class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int n = colors.size();
    vector<int> c = colors;
    for (int x : colors)
      c.push_back(x);

    vector<int> sum(n * 2, 0);
    for (int i = 0; i + 1 < n * 2; i++) {
      sum[i] = (i > 0 ? sum[i - 1] : 0) + int(c[i] != c[i + 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int got = sum[i + k - 2] - (i == 0 ? 0 : sum[i - 1]);
      if (got == k - 1)
        ans++;
    }
    return ans;
  }
};
