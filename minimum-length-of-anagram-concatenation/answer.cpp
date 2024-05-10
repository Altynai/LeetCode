const int N = 26;

class Solution {
public:
  int minAnagramLength(string s) {
    int n = s.size();
    vector<vector<int>> freq(n + 1, vector<int>(N, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < N; j++)
        freq[i][j] = freq[i - 1][j];
      freq[i][s[i - 1] - 'a']++;
    }

    auto Test = [&](int len) -> bool {
      for (int i = len; i <= n; i += len) {
        for (int j = 0; j < N; j++) {
          if (freq[i][j] - freq[i - len][j] != freq[len][j])
            return 0;
        }
      }
      return 1;
    };

    for (int i = 1; i < n; i++) {
      if (n % i == 0 and Test(i))
        return i;
    }
    return n;
  }
};
