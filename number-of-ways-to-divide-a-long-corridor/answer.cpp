const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfWays(string s) {
    vector<int> pos;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'S')
        pos.push_back(i);
    }

    int n = pos.size();
    if (n == 0 or n % 2 == 1)
      return 0;

    int ans = 1;
    for (int i = 2; i < n; i += 2)
      ans = 1LL * ans * (pos[i] - pos[i - 1]) % MOD;
    return ans;
  }
};
