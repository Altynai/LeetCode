class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int n = s.size(), one = count(s.begin(), s.end(), '1');
    string ans(n, '0');
    for (int i = 0; i < one - 1; i++)
      ans[i] = '1';
    ans[n - 1] = '1';
    return ans;
  }
};
