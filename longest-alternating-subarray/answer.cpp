class Solution {
public:
  int alternatingSubarray(vector<int> &a) {
    int n = a.size(), ans = -1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i + 1] != a[i] + 1)
        continue;

      int j = i + 2;
      while (j < n and a[j] == a[j - 2])
        j++;
      ans = max(ans, j - i);
    }
    return ans;
  }
};
