class Solution {
public:
  int smallestDistancePair(vector<int> &a, int k) {
    int n = a.size();
    int ans = -1;
    sort(a.begin(), a.end());

    for (int l = 0, r = a[n - 1] - a[0]; l <= r;) {
      int d = (l + r) / 2, cnt = 0;
      for (int i = 1, j = 0; i < n; i++) {
        while (j < i and a[i] - a[j] > d)
          j++;
        cnt += i - j;
      }
      if (cnt >= k)
        ans = d, r = d - 1;
      else
        l = d + 1;
    }
    return ans;
  }
};
