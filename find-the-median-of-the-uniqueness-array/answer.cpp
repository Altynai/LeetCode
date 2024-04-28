using int64 = long long;

class Solution {
public:
  int medianOfUniquenessArray(vector<int> &a) {
    int n = a.size();
    int maxv = *max_element(a.begin(), a.end());
    int64 total = 1LL * n * (n + 1) / 2;

    vector<int> freq(maxv + 1, 0);
    int uniq = 0;

    // count number of subarrays with uniqueness <= x
    auto NumberOfArrays = [&](int x) -> int64 {
      int64 res = 0;

      freq.assign(maxv + 1, 0);
      uniq = 0;
      for (int j = 0, i = 0; j < n; j++) {
        if (freq[a[j]]++ == 0)
          uniq++;

        while (uniq > x and i < j) {
          if (--freq[a[i]] == 0)
            uniq--;
          i++;
        }
        res += j - i + 1;
      }
      return res;
    };

    int ans = -1;
    for (int l = 1, r = n; l <= r;) {
      int mid = (l + r) / 2;
      int64 cnt = NumberOfArrays(mid);
      if (cnt >= total - cnt)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
