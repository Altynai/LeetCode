class Solution {
public:
  int maxAdjacentDistance(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, abs(a[i] - a[(i + 1) % n]));
    return ans;
  }
};
