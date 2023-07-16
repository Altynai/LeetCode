class Solution {
public:
  int maximumBeauty(vector<int> &a, int k) {
    vector<pair<int, int>> p;
    for (int x : a) {
      p.push_back({x - k, 1});
      p.push_back({x + k + 1, -1});
    }

    sort(p.begin(), p.end());
    int n = p.size(), ans = 0, sum = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and p[j].first == p[i].first)
        sum += p[j++].second;
      ans = max(ans, sum);
      i = j;
    }
    return ans;
  }
};
