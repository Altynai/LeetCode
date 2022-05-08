const int MOD = 1e9 + 7;

void add(int &x, int y) {
  x += y;
  x %= MOD;
}

void mul(int &x, int y) {
  long long z = 1LL * x * y;
  x = z % MOD;
}

class Solution {
public:
  int countTexts(string s) {
    int n = s.size();

    vector<int> dp3(n + 1, 0), dp4(n + 1, 0);
    dp3[0] = dp4[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 4; j++) {
        if (i - j >= 0) {
          add(dp4[i], dp4[i - j]);
          if (j <= 3)
            add(dp3[i], dp3[i - j]);
        }
      }
    }

    int ans = 1;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and s[j] == s[i])
        j++;
      if (s[i] == '7' or s[i] == '9')
        mul(ans, dp4[j - i]);
      else
        mul(ans, dp3[j - i]);
      i = j;
    }
    return ans;
  }
};
