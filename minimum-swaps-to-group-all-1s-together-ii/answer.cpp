class Solution {
public:
  int minSwaps(vector<int> &a) {
    int n = a.size();
    int m = count(a.begin(), a.end(), 1);
    if (m <= 1)
      return 0;

    vector<int> cnt(2);
    for (int i = 0; i < m; i++)
      cnt[a[i]]++;

    int ans = cnt[0];
    for (int i = 1; i < n; i++) {
      cnt[a[i - 1]] -= 1;
      cnt[a[(i - 1 + m) % n]] += 1;
      ans = min(ans, cnt[0]);
    }
    return ans;
  }
};
