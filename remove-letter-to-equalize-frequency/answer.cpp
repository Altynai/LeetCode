class Solution {
public:
  bool equalFrequency(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      map<char, int> cnt;
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        cnt[s[j]]++;
      }
      set<int> feq;
      for (auto [k, v] : cnt)
        feq.insert(v);
      if (feq.size() == 1)
        return 1;
    }
    return 0;
  }
};
