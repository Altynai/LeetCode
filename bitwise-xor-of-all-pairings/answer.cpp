#define bit(n, i) (((n) >> (i)) & 1)

const int N = 30;

class Solution {
public:
  int xorAllNums(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      int cnta[2] = {0, 0};
      int cntb[2] = {0, 0};

      for (int j = 0; j < n; j++)
        cnta[bit(a[j], i)]++;
      for (int j = 0; j < m; j++)
        cntb[bit(b[j], i)]++;

      long long x = 1LL * cnta[0] * cntb[1] + 1LL * cnta[1] * cntb[0];
      if (x & 1)
        ans |= (1 << i);
    }
    return ans;
  }
};
