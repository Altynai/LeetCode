class Solution {
public:
  vector<int> secondGreaterElement(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);

    vector<pair<int, int>> p;
    for (int i = n - 1; i >= 0; i--)
      p.push_back({a[i], i});
    sort(p.begin(), p.end());

    set<int> where;
    for (int i = n - 1; i >= 0;) {
      int j = i;
      while (j >= 0 and p[j].first == p[i].first) {
        auto [val, pos] = p[j--];
        auto it = where.upper_bound(pos);
        if (it != where.end() and ++it != where.end())
          ans[pos] = a[*it];
      }

      j = i;
      while (j >= 0 and p[j].first == p[i].first)
        where.insert(p[j--].second);

      i = j;
    }

    return ans;
  }
};
