class Solution {
public:
  vector<int> evenOddBit(int n) {
    vector<int> cnt(2, 0);
    for (int p = 0; n > 0; p ^= 1) {
      if (n & 1)
        cnt[p]++;
      n /= 2;
    }
    return cnt;
  }
};
