class Solution {
public:
  bool isGood(vector<int> &a) {
    int n = a.size();
    n -= 1;
    vector<int> cnt(n + 1, 0);
    for (int x : a) {
      if (x > n)
        return 0;
      cnt[x]++;
      if (x < n and cnt[x] > 1)
        return 0;
      if (x == n and cnt[x] > 2)
        return 0;
    }
    return 1;
  }
};
