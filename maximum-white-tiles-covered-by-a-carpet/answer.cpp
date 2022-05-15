class Solution {
public:
  int maximumWhiteTiles(vector<vector<int>> &a, int len) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int> gaps(n, 0);
    for (int i = 1; i < n; i++)
      gaps[i] = gaps[i - 1] + (a[i][0] - a[i - 1][1] - 1);

    int ans = 0;
    for (int i = 0, j = 1; i < n; i++) {
      // match left endpoint
      int end = a[i][0] + len - 1;
      while (j < n and end >= a[j][0])
        j++;

      int gap = gaps[j - 1] - gaps[i];
      int sum = min(a[j - 1][1], end) - a[i][0] + 1;
      ans = max(ans, sum - gap);
    }
    return ans;
  }
};
