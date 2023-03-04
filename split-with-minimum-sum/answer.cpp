class Solution {
public:
  int splitNum(int n) {
    vector<int> cnt(10, 0);
    for (int x = n; x > 0; x /= 10)
      cnt[x % 10]++;

    int a = 0, b = 0;
    for (int i = 1; i <= 9; i++) {
      while (cnt[i]) {
        if (a <= b)
          a = a * 10 + i;
        else
          b = b * 10 + i;
        cnt[i]--;
      }
    }
    return a + b;
  }
};
