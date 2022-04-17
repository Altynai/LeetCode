class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks)
      cnt[t]++;

    int ans = 0;
    for (auto &[k, v] : cnt) {
      if (v == 1)
        return -1;

      if (v % 3 == 0)
        ans += v / 3;
      else if (v % 3 == 1)
        ans += (v - 4) / 3 + 2;
      else
        ans += (v - 2) / 3 + 1;
    }
    return ans;
  }
};
