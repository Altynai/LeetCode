class Solution {
public:
  int bestClosingTime(string s) {
    int n = s.size();
    vector<int> cnty(n + 1, 0);
    for (int i = 1; i <= n; i++)
      cnty[i] = cnty[i - 1] + int(s[i - 1] == 'Y');

    int ans = 0, p = cnty[n];
    for (int i = 1; i <= n; i++) {
      int k = (i - cnty[i]) + (cnty[n] - cnty[i]);
      if (k < p)
        ans = i, p = k;
    }
    return ans;
  }
};
