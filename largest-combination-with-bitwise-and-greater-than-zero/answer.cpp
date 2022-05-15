#define bit(n, i) (((n) >> (i)) & 1)

const int N = 30;

class Solution {
public:
  int largestCombination(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int x : a)
        if (bit(x, i))
          cnt++;
      ans = max(ans, cnt);
    }
    return ans;
  }
};
