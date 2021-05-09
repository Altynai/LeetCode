class Solution {
public:
  int maxDistance(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    int ans = 0;
    for (int i = 0, j = 0; i < min(n, m); i++) {
      while (j < m && (j < i || b[j] >= a[i]))
        j++;
      ans = max(ans, j - i - 1);
    }
    return ans;
  }
};
