class Solution {
private:
  bool isRepeated(string &t, int k, string &s) {
    int n = t.size(), m = s.size(), cnt = 0;
    for (int i = 0, j = 0; i < m; i++) {
      if (s[i] == t[j]) {
        j = (j + 1) % n;
        if (j == 0)
          cnt++;
        if (cnt == k)
          return 1;
      }
    }
    return 0;
  }

public:
  string longestSubsequenceRepeatedK(string s, int k) {
    map<char, int> cnt;
    for (char c : s)
      cnt[c]++;

    string cand;
    for (auto [ch, t] : cnt) {
      for (int i = 0; i < t / k; i++)
        cand.push_back(ch);
    }

    string ans = "";
    for (int len = cand.size(); len >= 1; len--) {
      if (len < ans.size())
        break;

      string temp = cand;
      sort(temp.begin(), temp.end());

      do {
        string t = temp.substr(0, len);
        if (isRepeated(t, k, s))
          ans = max(ans, t);
      } while (next_permutation(temp.begin(), temp.end()));
    }
    return ans;
  }
};
