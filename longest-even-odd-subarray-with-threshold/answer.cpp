class Solution {
public:
  int longestAlternatingSubarray(vector<int> &a, int threshold) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] & 1)
        continue;
      if (a[i] > threshold)
        continue;
      int j = i + 1;
      while (j < n and a[j] <= threshold and a[j] % 2 != a[j - 1] % 2)
        j++;
      ans = max(ans, j - i);
    }
    return ans;
  }
};
