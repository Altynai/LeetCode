class Solution {
public:
  long long countBadPairs(vector<int> &a) {
    long long ans = 0;
    map<int, int> cnt;
    int n = a.size();
    for (int i = 0; i < n; i++) {
      int k = i - a[i];
      ans += i - cnt[k];
      cnt[k]++;
    }
    return ans;
  }
};
