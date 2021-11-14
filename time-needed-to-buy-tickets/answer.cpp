class Solution {
public:
  int timeRequiredToBuy(vector<int> &a, int k) {
    int n = a.size(), ans = 0, sum = 0;
    for (int i = 0; i < k; i++) {
      ans++;
      a[i]--;
      sum += min(a[i], a[k] - 1);
    }
    ans++, a[k]--;
    for (int i = k + 1; i < n; i++)
      sum += min(a[i], a[k]);
    return ans + sum + a[k];
  }
};
