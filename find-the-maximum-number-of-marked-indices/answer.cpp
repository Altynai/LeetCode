class Solution {
public:
  int maxNumOfMarkedIndices(vector<int> &a) {
    sort(a.begin(), a.end());

    int n = a.size(), ans = 0;
    for (int l = 1, r = n; l <= r;) {
      int mid = (l + r) / 2, cnt = 0;
      for (int i = 0, j = mid; j < n and i < mid; i++) {
        while (j < n and a[i] * 2 > a[j])
          j++;
        if (j < n)
          cnt++, j++;
      }
      if (cnt == mid)
        ans = cnt, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans * 2;
  }
};
