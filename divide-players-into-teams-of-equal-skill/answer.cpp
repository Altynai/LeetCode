using int64 = long long;

class Solution {
public:
  int64 dividePlayers(vector<int> &a) {
    int64 sum = accumulate(a.begin(), a.end(), 0LL);
    int n = a.size();
    int teams = n / 2;

    if (sum % teams != 0)
      return -1;

    int64 each = sum / teams;
    map<int, int> cnt;
    for (int x : a)
      cnt[x]++;

    int64 ans = 0;
    for (auto [x, c] : cnt) {
      int y = each - x;
      if (c != cnt[y])
        return -1;
      ans += 1LL * x * y * c;
    }
    return ans / 2;
  }
};
