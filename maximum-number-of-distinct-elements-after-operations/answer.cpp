class Solution {
public:
  int maxDistinctElements(vector<int> &a, int k) {
    vector<pair<int, int>> p;
    for (int x : a)
      p.push_back({x - k, x + k});

    int n = p.size();
    sort(p.begin(), p.end());

    int last = p[0].first, ans = 1;
    for (int i = 1; i < n; i++) {
      if (last < p[i].first)
        last = p[i].first, ans++;
      else if (last + 1 <= p[i].second)
        ¨ last++, ans++;
      // last >= p[i].second
    }
    return ans;
  }
};
