using int64 = long long;

class Solution {
public:
  vector<long long> findPrefixScore(vector<int> &a) {
    int n = a.size();
    vector<int64> ans(n, 0);

    int conver = 0;
    for (int i = 0; i < n; i++) {
      conver = max(conver, a[i]);
      ans[i] = a[i] + conver;
    }

    for (int i = 1; i < n; i++)
      ans[i] += ans[i - 1];
    return ans;
  }
};
