class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    const int N = 26;
    int ans = 0;
    vector<int> l(N, -1), r(N, -1);
    while (s.size() >= 2) {
      l.assign(N, -1), r.assign(N, -1);
      int n = s.size();
      for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        r[j] = i;
        if (l[j] == -1)
          l[j] = i;
      }
      int k = -1;
      for (int i = 0; i < N; i++) {
        if (r[i] == -1)
          continue;

        if (k == -1)
          k = i;
        else if (l[i] - r[i] < l[k] - r[k])
          k = i;
      }
      assert(k != -1);
      ans += l[k] + n - 1 - r[k];

      int m = 0;
      for (int i = 0; i < n; i++) {
        if (i != l[k] && i != r[k])
          s[m++] = s[i];
      }
      s.resize(m);
    }
    return ans;
  }
};
