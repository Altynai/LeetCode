class Solution {
public:
  bool makeStringsEqual(string s, string t) {
    // 0 0 -> 0 0 (not useful)
    // 0 1 -> 1 1
    // 1 0 -> 1 1
    // 1 1 -> 1 0

    int n = s.size();
    int freq[2][2] = {0};
    for (int i = 0; i < n; i++)
      freq[s[i] - '0'][t[i] - '0']++;

    for (int k = 0; k < 2; k++) {
      // 11 -> 10
      // X0    X0
      if (freq[1][0]) {
        if (freq[1][1]) {
          freq[0][0] += freq[1][0];
          freq[1][0] = 0;
        } else if (freq[1][0] > 1) {
          freq[0][0] += freq[1][0] - 1;
          freq[1][0] = 1;
        }
      }

      // 10 -> 11
      // X1    X1
      if (freq[0][1]) {
        if (freq[1][1]) {
          freq[1][1] += freq[0][1];
          freq[0][1] = 0;
        } else if (freq[1][0]) {
          freq[1][1] += freq[0][1];
          freq[0][1] = 0;
        }
      }
    }
    return freq[1][1] + freq[0][0] == n;
  }
};
