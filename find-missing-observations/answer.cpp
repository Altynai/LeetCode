class Solution {
public:
  vector<int> missingRolls(vector<int> &a, int mean, int n) {
    int m = a.size();
    int sum = mean * (n + m) - accumulate(a.begin(), a.end(), 0);
    if (sum < n || sum > n * 6)
      return {};

    vector<int> ans(n, 1);
    sum -= n;
    for (int i = 0; i < n && sum > 0; i++) {
      int used = min(sum, 5);
      ans[i] += used;
      sum -= used;
    }
    return ans;
  }
};
