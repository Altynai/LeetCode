class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> diff, same;
    for (string s : words) {
      if (s[0] == s[1])
        same[s] += 1;
      else
        diff[s] += 1;
    }
    int ans = 0;
    for (auto [s, cc] : diff) {
      string t = {s[1], s[0]};
      ans += min(cc, diff[t]);
    }

    bool used = 0;
    for (auto [s, cc] : same) {
      if (cc % 2 == 1 && !used) {
        ans += 1;
        cc -= 1;
        used = 1;
      }
      ans += cc / 2 * 2;
    }
    return ans * 2;
  }
};
