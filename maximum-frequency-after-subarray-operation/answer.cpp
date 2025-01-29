const int N = 51;

class Solution {
public:
  int maxFrequency(vector<int> &a, int k) {
    // for a fixed value, if we choose to change a[l ... r]
    // ans = (cnt[r][x] - cnt[l - 1][x]) + cnt[n - 1][k] - (cnt[r][k] - cnt[l -
    // 1][k]) ans = C + (cnt[r][x] - cnt[r][k]) - (cnt[l - 1][x] - cnt[l -
    // 1][k]) so we can maintain cnt[r][x] - cnt[r][k]

    int n = a.size();
    int ans = 0, total = count(a.begin(), a.end(), k);
    for (int x = 1; x <= 50; x++) {
      if (x == k)
        continue;
      int mi = 0, best = 0, sum = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == x)
          sum++;
        else if (a[i] == k)
          sum--;
        best = max(best, sum - mi);
        mi = min(mi, sum);
      }
      ans = max(ans, total + best);
    }
    return ans;
  }
};
