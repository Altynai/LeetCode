class Solution {
public:
  int maxFrequencyElements(vector<int> &a) {
    unordered_map<int, int> cnt;
    int best = 0;
    for (int x : a)
      best = max(best, ++cnt[x]);

    int ans = 0;
    for (auto [k, v] : cnt) {
      if (v == best)
        ans += v;
    }
    return ans;
  }
};
