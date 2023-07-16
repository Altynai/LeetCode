class Solution {
public:
  int minimumIndex(vector<int> &a) {
    unordered_map<int, int> cnt;
    int n = a.size();
    int dom = -1, p = 0;
    for (int x : a) {
      if (++cnt[x] > p) {
        p = cnt[x];
        dom = x;
      }
    }

    int y = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] == dom)
        y++;
      if (y * 2 > i + 1 and (p - y) * 2 > (n - i - 1))
        return i;
    }
    return -1;
  }
};
