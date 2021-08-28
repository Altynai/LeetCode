class Solution {
public:
  vector<int> recoverArray(int n, vector<int> &sums) {
    vector<int> ans(n, 0);

    function<bool(int, vector<int> &)> dfs = [&](int i,
                                                 vector<int> &s) -> bool {
      int m = s.size();

      if (i == n - 1) {
        assert(m == 2);
        if (s[0] != 0 && s[1] != 0)
          return false;
        ans[i] = s[0] + s[1];
        return true;
      }

      int positive = s[m - 1] - s[m - 2];
      multiset<int> ms(s.begin(), s.end());
      vector<int> small, big;
      while (!ms.empty()) {
        auto it = prev(ms.end());
        auto it2 = ms.find(*it - positive);
        if (it2 == ms.end() || it == it2)
          break;

        small.emplace_back(*it2);
        big.emplace_back(*it);

        ms.erase(it);
        ms.erase(it2);
      }

      if (small.size() == m / 2 && big.size() == m / 2) {
        ans[i] = positive;
        sort(small.begin(), small.end());
        if (dfs(i + 1, small))
          return true;
      }

      ms.clear(), small.clear(), big.clear();

      int negative = -(s[m - 1] - s[m - 2]);
      ms.insert(s.begin(), s.end());
      while (!ms.empty()) {
        auto it = ms.begin();
        auto it2 = ms.find(*it - negative);
        if (it2 == ms.end() || it == it2)
          break;

        small.emplace_back(*it);
        big.emplace_back(*it2);

        ms.erase(it2);
        ms.erase(it);
      }

      if (small.size() == m / 2 && big.size() == m / 2) {
        ans[i] = negative;
        sort(big.begin(), big.end());
        if (dfs(i + 1, big))
          return true;
      }
      return false;
    };

    sort(sums.begin(), sums.end());
    assert(dfs(0, sums));
    return ans;
  }
};
