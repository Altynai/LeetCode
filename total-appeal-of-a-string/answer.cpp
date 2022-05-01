class Solution {
public:
  long long appealSum(string s) {
    int n = s.size();
    long long ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int last = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == ch)
          last = i;
        if (last != -1)
          ans += last + 1;
      }
    }
    return ans;
  }
};
