class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    map<pair<int, int>, int> cnt;
    long long ans = 0;
    for (auto &r : rectangles) {
      int g = gcd(r[0], r[1]);
      pair<int, int> p = {r[0] / g, r[1] / g};
      auto it = cnt.find(p);
      if (it != cnt.end())
        ans += it->second;
      cnt[p] += 1;
    }
    return ans;
  }
};
