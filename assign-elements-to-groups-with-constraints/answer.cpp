class Solution {
public:
  vector<int> assignElements(vector<int> &groups, vector<int> &elements) {
    int n = groups.size(), m = elements.size();

    unordered_map<int, int> where;
    for (int i = 0; i < m; i++) {
      if (where.count(elements[i]) == 0)
        where[elements[i]] = i;
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      int q = sqrt(groups[i]);
      int best = INT_MAX;
      for (int p = 1; p <= q; p++) {
        if (groups[i] % p != 0)
          continue;
        auto it = where.find(p);
        if (it != where.end())
          best = min(best, it->second);
        it = where.find(groups[i] / p);
        if (it != where.end())
          best = min(best, it->second);
      }
      if (best != INT_MAX)
        ans[i] = best;
    }
    return ans;
  }
};
