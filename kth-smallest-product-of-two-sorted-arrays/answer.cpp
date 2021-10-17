using ll = long long;

class Solution {
public:
  ll kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, ll k) {
    vector<ll> a(nums1.begin(), nums1.end());
    vector<ll> b(nums2.begin(), nums2.end());

    int n = a.size(), m = b.size();
    vector<ll> c = {1LL * a[0] * b[0], 1LL * a[0] * b[m - 1],
                    1LL * a[n - 1] * b[0], 1LL * a[n - 1] * b[m - 1]};

    auto count = [&](int val, ll ma) -> int {
      if (val == 0) {
        // val * b[i] = 0 <= ma
        if (ma < 0)
          return 0;
        else
          return m;
      } else if (val > 0) {
        if (ma >= 0) {
          // val * b[i] <= ma
          // val > 0 && ma >= 0 && b[i] <= ma / val
          return lower_bound(b.begin(), b.end(), ma / val + 1) - b.begin();
        } else {
          // val > 0 && ma < 0
          // b[i] >= 0 -> all bad

          // b[i] < 0 && val * b[i] <= ma
          // b[i] <= -1 && b[i] <= ma / val
          ll lim = min(ma % val == 0 ? ma / val : ma / val - 1, -1LL);
          return lower_bound(b.begin(), b.end(), lim + 1) - b.begin();
        }
      } else {
        if (ma >= 0) {
          // val < 0 && ma >= 0
          // b[i] >= 0 -> all good
          // b[i] < 0 && val * b[i] <= ma
          // b[i] <= -1 && b[i] >= ma / val

          // -2 * ? <= 0
          ll lim = -(ma / llabs(val));
          return b.end() - lower_bound(b.begin(), b.end(), lim);
        } else {
          // ma < 0 && val < 0
          // b[i] <= 0 -> all bad

          // b[i] >= 1 && val * b[i] <= ma
          // b[i] >= ma / val
          // -2 * ? <= -8
          ll lim = (llabs(ma) + llabs(val) - 1) / llabs(val);
          return b.end() - lower_bound(b.begin(), b.end(), lim);
        }
      }
    };

    ll l = *min_element(c.begin(), c.end()),
       r = *max_element(c.begin(), c.end());
    ll ans = 0;
    while (l <= r) {
      ll mid = (l + r) >> 1, cnt = 0;
      for (int val : a)
        cnt += count(val, mid);

      if (cnt >= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
