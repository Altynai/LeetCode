class Solution {
public:
  int reductionOperations(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> cnt;
    int l = 0;
    while (l < n) {
      int r = l;
      while (r < n && a[r] == a[l])
        r++;
      cnt.push_back(r - l);
      l = r;
    }
    int m = cnt.size(), ans = 0;
    for (int i = m - 1; i >= 1; i--)
      ans += i * cnt[i];
    return ans;
  }
};
