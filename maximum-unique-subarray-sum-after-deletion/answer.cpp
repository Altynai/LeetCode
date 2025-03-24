class Solution {
public:
  int maxSum(vector<int> &a) {
    set<int> s(a.begin(), a.end());

    int mx = *prev(s.end());
    if (mx < 0)
      return mx;

    int ans = 0;
    for (int x : s)
      ans += max(x, 0);
    return ans;
  }
};
