using int64 = long long;

class Solution {
public:
  int64 minimumTotalCost(vector<int> &a, vector<int> &b) {
    int n = a.size();

    unordered_map<int, int> cnt;
    int m = 0;
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        ans += i;
        cnt[a[i]]++;
        m++;
      }
    }

    int key = -1;
    for (auto [k, c] : cnt) {
      if (c > m / 2)
        key = k;
    }
    if (key == -1)
      return ans;

    int extra = cnt[key] - (m - cnt[key]);
    for (int i = 0; extra > 0 and i < n; i++) {
      if (a[i] != b[i] and a[i] != key and b[i] != key)
        extra--, ans += i;
    }
    return extra > 0 ? -1 : ans;
  }
};
