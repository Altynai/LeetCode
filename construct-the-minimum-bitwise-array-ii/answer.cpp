class Solution {
public:
  vector<int> minBitwiseArray(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 2)
        continue;

      // if a[i] is repsented as ???????0111...11
      // we can choose the sum of:
      // ???????0011...11  <- ans[i]
      // ???????0100...00  <- ans[i] + 1
      // ???????0111...11  <- a[i]

      int cnt = 0;
      for (int x = a[i]; x % 2 == 1; x /= 2)
        cnt++;
      ans[i] = a[i] ^ (1 << (cnt - 1));
    }
    return ans;
  }
};
