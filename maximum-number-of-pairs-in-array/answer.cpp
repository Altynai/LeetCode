class Solution {
public:
  vector<int> numberOfPairs(vector<int> &a) {
    map<int, int> cnt;
    for (int x : a)
      cnt[x]++;
    int p = 0;
    for (auto [k, v] : cnt)
      p += v / 2;
    return {p, (int)a.size() - p * 2};
  }
};
