const int MOD = 1e9 + 7;

class Solution {
public:
  int countPermutations(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
      if (a[i] <= a[0])
        return 0;
    }

    int ans = 1;
    for (int i = 1; i < n; i++)
      ans = 1LL * ans * (n - i) % MOD;
    return ans;
  }
};
