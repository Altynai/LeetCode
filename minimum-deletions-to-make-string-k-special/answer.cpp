const int N = 26;

class Solution {
public:
  int minimumDeletions(string s, int k) {
    int n = s.size();
    vector<int> cnt(N, 0);
    for (char ch : s)
      cnt[ch - 'a']++;

    sort(cnt.begin(), cnt.end());
    vector<int> suffix = cnt;
    for (int i = N - 2; i >= 0; i--)
      suffix[i] = suffix[i + 1] + cnt[i];

    int ans = n;
    for (int i = 0, j = 0, prefix = 0; i < N; i++) {
      while (j < N and cnt[j] - cnt[i] <= k)
        j++;
      if (j == N)
        ans = min(ans, prefix);
      else
        ans = min(ans, prefix + suffix[j] - (cnt[i] + k) * (N - j));
      prefix += cnt[i];
    }
    return ans;
  }
};
