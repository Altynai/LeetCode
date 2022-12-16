class Solution {
public:
  int getValue(const string &s) {
    int n = s.size(), val = 0;
    for (int i = 0; i < n; i++) {
      if (isdigit(s[i]))
        val = val * 10 + (s[i] - '0');
      else
        return n;
    }
    return val;
  }
  int maximumValue(vector<string> &a) {
    int ans = 0;
    for (string &s : a)
      ans = max(ans, getValue(s));
    return ans;
  }
};
