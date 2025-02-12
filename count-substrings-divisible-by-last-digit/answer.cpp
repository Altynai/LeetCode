using int64 = long long;

class Solution {
private:
  int numeric(const string &s, int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++)
      res = res * 10 + (s[i] - '0');
    return res;
  }

public:
  long long countSubstrings(string s) {
    int n = s.size();
    int64 ans = 0;

    // 1, 2, 5
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1' or s[i] == '2' or s[i] == '5')
        ans += i + 1;
    }

    // 3
    vector<int> mods(3, 0);
    mods[0] = 1;
    for (int i = 1, sum = 0; i <= n; i++) {
      sum += s[i - 1] - '0';
      if (s[i - 1] == '3')
        ans += mods[sum % 3];
      mods[sum % 3]++;
    }

    // 4
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '4') {
        ans++;
        // 04, 24, 44, 64, 84
        if (i > 0 and numeric(s, i - 1, i) % 4 == 0)
          ans += i;
      }
    }

    // 6
    mods.assign(3, 0);
    mods[0] = 1;
    for (int i = 1, sum = 0; i <= n; i++) {
      sum += s[i - 1] - '0';
      if (s[i - 1] == '6')
        ans += mods[sum % 3];
      mods[sum % 3]++;
    }

    // 7: 个位数乘5，加到其余位中，其结果能被7整除。
    mods = vector<int>(7, 0);
    for (int i = 1, sum = 0; i <= n; i++) {
      vector<int> mods2(7, 0);
      int d = s[i - 1] - '0';
      sum += d;
      if (s[i - 1] == '7')
        ans += mods[0] + 1;

      mods2[d % 7]++;
      for (int j = 0; j < 7; j++) {
        mods2[(j * 10 + d) % 7] += mods[j];
      }

      swap(mods, mods2);
    }

    // 8
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '8') {
        ans++;
        if (i > 0 and numeric(s, i - 1, i) % 8 == 0)
          ans++;
        if (i > 1 and numeric(s, i - 2, i) % 8 == 0)
          ans += i - 1;
      }
    }

    // 9
    mods = vector<int>(9, 0);
    mods[0] = 1;
    for (int i = 1, sum = 0; i <= n; i++) {
      sum += s[i - 1] - '0';
      if (s[i - 1] == '9')
        ans += mods[sum % 9];
      mods[sum % 9]++;
    }
    return ans;
  }
};
