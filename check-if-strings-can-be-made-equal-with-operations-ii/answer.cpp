const int N = 26;

class Solution {
public:
  bool checkStrings(string s1, string s2) {
    int n = s1.size();
    for (int i = 0; i <= 1; i++) {
      vector<int> cnt(N);
      for (int j = i; j < n; j += 2) {
        cnt[s1[j] - 'a']++;
        cnt[s2[j] - 'a']--;
      }
      for (int j = 0; j < N; j++) {
        if (cnt[j] != 0)
          return 0;
      }
    }
    return 1;
  }
};
