class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<int> cnt(n, 0);
    for (auto &road : roads) {
      cnt[road[0]]++;
      cnt[road[1]]++;
    }
    sort(cnt.begin(), cnt.end());

    long long ans = 0;
    for (int i = n - 1, p = n; i >= 0; i--, p--)
      ans += 1LL * p * cnt[i];
    return ans;
  }
};
