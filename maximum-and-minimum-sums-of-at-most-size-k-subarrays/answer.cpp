using int64 = long long;

class Solution {
private:
  int64 times(int l, int r, int k) {
    // l elements to the left
    // r elements to the right
    // Total # of subarrays - # of subarrays with length > k

    int extra = max(0, l + r - 1 - k);
    // # subarrays with extra excess elements: 1
    // # subarrays with extra - 1 excess elements: 2
    // ...
    // # subarrays with 1 excess elements: extra
    int64 sub = (1LL * extra * (extra + 1)) / 2;
    return 1LL * l * r - sub;
  };

public:
  long long minMaxSubarraySum(vector<int> &a, int k) {
    int n = a.size();

    vector<int> prefix_max(n), prefix_min(n);
    vector<int> suffix_max(n), suffix_min(n);

    vector<int> dec, inc;
    for (int i = 0; i < n; i++) {
      prefix_max[i] = prefix_min[i] = i;

      while (dec.size() > 0 and a[dec.back()] <= a[i])
        dec.pop_back();
      if (dec.size())
        prefix_max[i] = dec.back() + 1;
      else
        prefix_max[i] = 0;
      dec.push_back(i);

      while (inc.size() > 0 and a[inc.back()] >= a[i])
        inc.pop_back();
      if (inc.size())
        prefix_min[i] = inc.back() + 1;
      else
        prefix_min[i] = 0;
      inc.push_back(i);
    }

    dec.clear(), inc.clear();
    for (int i = n - 1; i >= 0; i--) {
      suffix_max[i] = suffix_min[i] = i;

      while (inc.size() > 0 and a[inc.back()] < a[i])
        inc.pop_back();
      if (inc.size())
        suffix_max[i] = inc.back() - 1;
      else
        suffix_max[i] = n - 1;
      inc.push_back(i);

      while (dec.size() > 0 and a[dec.back()] > a[i])
        dec.pop_back();
      if (dec.size())
        suffix_min[i] = dec.back() - 1;
      else
        suffix_min[i] = n - 1;
      dec.push_back(i);
    }

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int l = i - max(prefix_max[i], i - k + 1) + 1;
      int r = min(suffix_max[i], i + k - 1) - i + 1;
      ans += times(l, r, k) * a[i];

      l = i - max(prefix_min[i], i - k + 1) + 1;
      r = min(suffix_min[i], i + k - 1) - i + 1;
      ans += times(l, r, k) * a[i];
    }
    return ans;
  }
};
