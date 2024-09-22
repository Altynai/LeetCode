using int64 = long long;

const int N = 26;

class Solution {
public:
  long long validSubstringCount(string word1, string word2) {
    vector<int> cnt(N, 0), freq(N, 0);
    for (char ch : word2)
      cnt[ch - 'a']++;

    auto Valid = [&]() -> bool {
      for (int i = 0; i < N; i++) {
        if (cnt[i] > 0 and freq[i] < cnt[i])
          return false;
      }
      return true;
    };

    int n = word1.size();
    int64 ans = 0;
    for (int j = 0, i = 0; j < n; j++) {
      freq[word1[j] - 'a']++;
      while (i <= j and Valid())
        freq[word1[i++] - 'a']--;
      ans += i;
    }
    return ans;
  }
};
