class Solution {
public:
  vector<int> findOriginalArray(vector<int> &a) {
    int n = a.size();
    if (n & 1)
      return {};

    int m = n / 2;
    map<int, int> cnt;
    for (int v : a)
      cnt[v]++;

    vector<int> ans;
    while (!cnt.empty()) {
      auto [k, v] = *cnt.begin();
      if (k == 0) {
        if (v & 1)
          return {};
        for (int i = 0; i < v / 2; i++)
          ans.push_back(k);
        cnt.erase(cnt.begin());
        continue;
      }

      auto it = cnt.find(k * 2);
      if (it == cnt.end())
        return {};

      if (it->second < v)
        return {};

      it->second -= v;
      for (int i = 0; i < v; i++)
        ans.push_back(k);
      if (it->second == 0)
        cnt.erase(it);
      cnt.erase(cnt.begin());
    }
    return ans;
  }
};
