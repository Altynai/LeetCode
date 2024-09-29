ousing int64 = long long;

const int N = 26;

class Solution {
private:
  bool isVowel(char ch) {
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
  }

public:
  long long countOfSubstrings(string s, int k) {
    int n = s.size();

    vector<int> cpos = {-1};     // consonant positions
    vector<vector<int>> vpos(N); // vowel positions
    for (int i = 0; i < n; i++) {
      if (isVowel(s[i]))
        vpos[s[i] - 'a'].push_back(i);
      else
        cpos.push_back(i);
    }

    auto Find = [&](int j) -> int {
      string t("aeiou");
      int res = INT_MAX;
      for (char ch : t) {
        int idx = ch - 'a';
        int pos = upper_bound(vpos[idx].begin(), vpos[idx].end(), j) -
                  vpos[idx].begin();
        if (pos == 0)
          return INT_MAX;
        res = min(res, vpos[idx][pos - 1]);
      }
      return res;
    };

    int64 ans = 0;
    int m = cpos.size();
    for (int j = 0; j < n; j++) {
      int y = upper_bound(cpos.begin() + 1, cpos.end(), j) - cpos.begin() - 1;

      // edge case
      if (k == 0) {
        if (isVowel(s[j]) and y < m) {
          int pos = Find(j);
          if (pos != INT_MAX and cpos[y] < pos)
            ans += pos - cpos[y];
        }
        continue;
      }

      if (y >= k && y < m) {
        int start = cpos[y - k];
        int end = cpos[y - k + 1];
        // (start, end] is a potential valid range

        // find the largest index p that s[p ... j] has all vowels
        int pos = Find(j);
        if (pos == INT_MAX)
          continue;
        if (pos > start)
          ans += min(end, pos) - start;
      }
    }
    return ans;
  }
};
