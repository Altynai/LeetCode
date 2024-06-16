const int N = 24;

class Solution {
public:
  int countCompleteDayPairs(vector<int> &h) {
    int ans = 0;
    vector<int> cnt(N, 0);
    for (int x : h)
      cnt[x % N]++;

    for (int i = 1; i < 12; i++) {
      if (cnt[i] > 0 and cnt[N - i] > 0)
        ans += cnt[i] * cnt[N - i];
    }
    if (cnt[0] > 0)
      ans += cnt[0] * (cnt[0] - 1) / 2;
    if (cnt[12] > 0)
      ans += cnt[12] * (cnt[12] - 1) / 2;
    return ans;
  }
};
