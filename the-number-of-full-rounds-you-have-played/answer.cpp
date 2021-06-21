class Solution {
public:
  int numberOfRounds(string a, string b) {
    int s = (a[0] - '0') * 10 * 60 + (a[1] - '0') * 60 + (a[3] - '0') * 10 +
            (a[4] - '0');
    int t = (b[0] - '0') * 10 * 60 + (b[1] - '0') * 60 + (b[3] - '0') * 10 +
            (b[4] - '0');

    if (t < s)
      t += 24 * 60;

    s = (s + 14) / 15 * 15;
    int ans = 0;
    while (s + 15 <= t) {
      ans++;
      s += 15;
    }
    return ans;
  }
};
