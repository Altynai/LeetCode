template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxRemovals(string source, string pattern, vector<int> &targetIndices) {
    // dp[i][j] = k
    // for source[0 ... i], we have selected j indices from targetIndices
    // and it matches pattern[0 ... k]

    int n = source.size(), m = pattern.size(),
        target_size = targetIndices.size();
    vector<int> dp(target_size + 1, INT_MIN);
    dp[0] = -1;

    for (int i = 0, j = 0; i < n; i++) {
      // we can just greedily transit on possible cases
      vector<int> ndp = dp;

      while (j < target_size and targetIndices[j] < i)
        j++;

      // normal position that not appears in targetIndices
      if (j == target_size or targetIndices[j] > i) {
        for (int selected = 0; selected <= target_size; selected++) {
          int pos = dp[selected];
          if (pos != INT_MIN and pos < m and source[i] == pattern[pos + 1])
            umax(ndp[selected], pos + 1);
        }
      }
      // appears in targetIndices
      else {
        assert(targetIndices[j] == i);
        for (int selected = 0; selected <= target_size; selected++) {
          int pos = dp[selected];
          // select this target index
          if (pos != INT_MIN and pos < m and source[i] == pattern[pos + 1])
            umax(ndp[selected + 1], pos + 1);
        }
      }
      swap(dp, ndp);
    }

    for (int selected = 0; selected <= target_size; selected++) {
      if (dp[selected] == m - 1)
        return target_size - selected;
    }
    return 0;
  }
};
