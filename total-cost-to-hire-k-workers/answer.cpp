using int64 = long long;

class Solution {
public:
  int64 totalCost(vector<int> &costs, int k, int m) {
    int n = costs.size();
    set<pair<int, int>> s;

    int i = 0, j = n - 1;
    for (; i < m; i++)
      s.insert({costs[i], i});
    for (; j >= n - m and j >= i; j--)
      s.insert({costs[j], j});

    int64 ans = 0;
    for (int p = 0; p < k; p++) {
      auto [cost, pos] = *s.begin();
      s.erase(s.begin());

      ans += cost;
      if (pos <= i and i <= j)
        s.insert({costs[i], i}), i++;
      else if (pos >= j and i <= j)
        s.insert({costs[j], j}), j--;
    }
    return ans;
  }
};
