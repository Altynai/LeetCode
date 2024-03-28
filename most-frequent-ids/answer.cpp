using int64 = long long;

class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int> &a, vector<int> &freq) {
    int n = a.size();
    multiset<int64> f;
    unordered_map<int, int64> p;
    vector<int64> ans(n);

    auto Update = [&](int val, int64 x, int64 y) -> int64 {
      auto it = f.find(x);
      if (it != f.end())
        f.erase(it);
      p[val] = y;
      f.insert(y);
      return *prev(f.end());
    };

    for (int i = 0; i < n; i++) {
      ans[i] = Update(a[i], p[a[i]], p[a[i]] + freq[i]);
    }
    return ans;
  }
};
