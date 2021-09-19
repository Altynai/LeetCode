class Solution {
public:
  int minOperations(vector<int> &a) {
    int n = a.size(), ans = INT_MAX;
    if (n == 1)
      return 0;

    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();

    // start
    int i = 0, j = 1;
    while (i < m) {
      int end = a[i] + n - 1;
      while (j < n && a[j] > a[j - 1] && a[j] <= end)
        j++;
      int had = j - i;
      ans = std::min(ans, n - had);
      i++;
    }

    // end
    i = m - 2;
    j = m - 1;
    while (j >= 0) {
      int start = a[j] - n + 1;
      while (i >= 0 && a[i] < a[i + 1] && a[i] >= start)
        i--;
      int had = j - i;
      ans = std::min(ans, n - had);
      j--;
    }

    return ans;
  }
};
