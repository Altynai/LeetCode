const int N = 30;

#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int x : a)
        cnt += bit(x, i);

      if (bit(k, i))
        ans += int(cnt % 2 == 0);
      else
        ans += int(cnt % 2 == 1);
    }
    return ans;
  }
};
