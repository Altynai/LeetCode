using int64 = long long;

class Solution {
public:
  long long minCost(vector<int> &a, vector<int> &b) {
    int n = a.size();
    map<int, int> cnt;
    for (int x : a)
      cnt[x]++;
    for (int x : b)
      cnt[x]--;

    for (auto [k, v] : cnt) {
      if (v % 2 == 1)
        return -1;
    }

    vector<int> want, extra;
    for (auto [k, v] : cnt) {
      if (v < 0) {
        for (int i = 0; i < -v / 2; i++)
          want.push_back(k);
      } else if (v > 0) {
        for (int i = 0; i < v / 2; i++)
          extra.push_back(k);
      }
    }

    int minb = *min_element(b.begin(), b.end());
    int m = want.size();
    assert(extra.size() == m);

    int64 ans = 0;
    for (int i = 0; i < m; i++) {
      // swap directly: minimal "extra" item in a with maximum "wanted" item
      // from b
      int cost = min(want[m - 1 - i], extra[i]);
      // swap "extra" <-> minb and then minb <-> "wanted"
      int cost2 = min(minb, extra[i]) + min(minb, want[m - 1 - i]);
      ans += min(cost, cost2);

      minb = min(minb, extra[i]);
    }
    return ans;
  }
};
