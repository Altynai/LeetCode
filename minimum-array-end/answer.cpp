using int64 = long long;

const int N = 32;

#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  long long minEnd(int n, int x) {
    if (n == 1)
      return x;

    n--;
    bitset<N> bs(n);
    int highest = -1;
    for (int i = N - 1; i >= 0; i--) {
      if (bs[i]) {
        highest = i;
        break;
      }
    }

    int64 ans = x;
    for (int i = 0, j = 0; i <= highest; i++) {
      while (bit(ans, j) == 1)
        j++;
      if (bs[i])
        ans |= (1LL << j);
      j++;
    }
    return ans;
  }
};
