class Solution {
public:
  int alternateDigitSum(int n) {
    string s = to_string(n);
    int ans = 0, sign = 1;
    for (char c : s) {
      ans += sign * (c - '0');
      sign *= -1;
    }
    return ans;
  }
};
