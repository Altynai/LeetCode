class Solution {
public:
  int mostFrequentEven(vector<int> &a) {
    map<int, int> cnt;
    for (int x : a)
      cnt[x]++;

    int ans = -1, tm = 0;
    for (auto [k, v] : cnt) {
      if (k % 2 == 0 and v > tm)
        ans = k, tm = v;
    }
    return ans;
  }
};
