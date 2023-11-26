using int64 = long long;

const string VOWELS = "aeiou";

class Solution {
private:
  bool isVowel(char c) { return VOWELS.find(c) != -1; }

public:
  long long beautifulSubstrings(string s, int k) {
    int n = s.size();
    unordered_map<int, unordered_map<int, int>> cnt;
    cnt[0][0] = 1;

    int v = 0, c = 0;
    int64 ans = 0;
    for (int i = 1; i <= n; i++) {
      if (isVowel(s[i - 1]))
        v += 1;
      else
        c += 1;

      // at most k elements in cnt[v - c]
      for (auto &[mod, count] : cnt[v - c]) {
        int z = v - mod;
        if (z * z % k == 0)
          ans += count;
      }
      cnt[v - c][v % k] += 1;
    }
    return ans;
  }
};
