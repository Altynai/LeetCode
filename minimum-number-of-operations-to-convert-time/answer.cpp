class Solution {
public:
  int convertTime(string a, string b) {
    auto convert = [&](const string &s) -> int {
      int h = (s[0] - '0') * 10 + (s[1] - '0');
      int m = (s[3] - '0') * 10 + (s[4] - '0');
      return h * 60 + m;
    };

    int d = convert(b) - convert(a);
    int ans = 0;
    for (int k : {60, 15, 5, 1}) {
      ans += d / k;
      d %= k;
    }
    return ans;
  }
};
