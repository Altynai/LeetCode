class Solution {
public:
  int countWays(vector<int> &a) {
    int ans = 0, n = a.size();
    sort(a.begin(), a.end());

    // no one is selected
    if (a[0] > 0)
      ans++;
    // all selected
    if (n > a[n - 1])
      ans++;

    for (int i = 1; i < n; i++) {
      // [0, i - 1] students are selected
      if (i <= a[i - 1])
        continue;
      // [i, n - 1] students are NOT selected
      if (i >= a[i])
        continue;
      ans++;
    }
    return ans;
  }
};
