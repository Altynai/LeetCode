using int64 = long long;

class Solution {
public:
  int64 countGood(vector<int> &a, int k) {
    int n = a.size();

    map<int, int> freq;
    int64 ans = 0, cnt = 0;

    auto Remove = [&](int val) {
      int x = freq[val];
      cnt -= x * (x - 1) / 2;

      x = --freq[val];
      cnt += x * (x - 1) / 2;
    };

    auto Add = [&](int val) {
      int x = freq[val];
      cnt -= x * (x - 1) / 2;

      x = ++freq[val];
      cnt += x * (x - 1) / 2;
    };

    for (int i = 0, j = 0; j < n; j++) {
      Add(a[j]);

      // try to maintain the max i satifies: a[i ... j] has cnt >= k
      while (i < j) {
        Remove(a[i++]);
        if (cnt < k) {
          Add(a[--i]);
          break;
        }
      }
      if (cnt >= k)
        ans += i + 1;
    }
    return ans;
  }
};
