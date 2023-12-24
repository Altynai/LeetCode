using int64 = long long;

class Solution {
public:
  long long incremovableSubarrayCount(vector<int> &a) {
    int n = a.size();
    // condition to remove [i + 1, j): a[i] < a[j], i and j are good positions
    // j is always increasing
    int j = n - 1;
    while (j > 0 and a[j - 1] < a[j])
      j--;

    if (j == 0)
      return 1LL * n * (n + 1) / 2;

    int64 ans = n - j + 1; // result is empty array or a non-empty suffix
    for (int i = 0; i < n; i++) {
      if (i > 0 and a[i] <= a[i - 1])
        break;
      while (j <= i)
        j++; // make sure j > i
      while (j < n and a[j] <= a[i])
        j++;
      ans +=
          n - j + 1; // we can remove any subarray: [i + 1, j), [i + 1, j], ....
    }
    return ans;
  }
};
