class Solution {
public:
  int maximumEnergy(vector<int> &a, int k) {
    int n = a.size(), ans = INT_MIN;
    vector<int> suffix(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      if (i + k < n)
        suffix[i] = suffix[i + k] + a[i];
      else
        suffix[i] = a[i];
      ans = max(ans, suffix[i]);
    }
    return ans;
  }
};
