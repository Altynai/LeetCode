class Solution {
public:
  string smallestSubsequence(string s, int k, char letter, int r) {
    int remain = count(s.begin(), s.end(), letter);
    int n = s.size(), m = 0;
    vector<char> stk;

    auto shouldPop = [&](int i) -> bool {
      if (stk.empty() || s[i] >= stk.back())
        return 0;
      // 1. we still have enough chars to construct length k
      // 2. we still have enough letters
      return ((n - i + stk.size() - 1) >= k) &&
             (m - (stk.back() == letter) + remain >= r);
    };

    for (int i = 0; i < n; i++) {
      // try to pop some letter to make the subseq lexicographically better
      while (shouldPop(i)) {
        char c = stk.back();
        stk.pop_back();
        if (c == letter)
          m--;
      }
      if (stk.size() < k) {
        if (s[i] == letter)
          stk.push_back(s[i]), m++;
        // we still have enough space for adding more letters to r times
        else if (k - stk.size() - 1 + m >= r)
          stk.push_back(s[i]);
      }

      if (s[i] == letter)
        remain--;
    }

    assert(stk.size() == k);
    return string(stk.begin(), stk.end());
  }
};
