class Solution {
public:
  string largestPalindromic(string s) {
    vector<int> cnt(10, 0);
    for (char ch : s)
      cnt[ch - '0']++;

    auto choose = [&](bool ok, int min) -> int {
      for (int i = 9; i >= (ok ? 0 : 1); i--) {
        if (cnt[i] >= min)
          return i;
      }
      return -1;
    };

    string t;
    int x;
    for (x = choose(false, 2); x != -1; x = choose(true, 2)) {
      t.push_back('0' + x);
      cnt[x] -= 2;
    }

    string t2 = t;
    reverse(t2.begin(), t2.end());

    x = choose(true, 1);
    if (x != -1)
      t.push_back('0' + x);
    return t + t2;
  }
};
