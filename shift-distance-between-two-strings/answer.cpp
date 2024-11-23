using int64 = long long;

class Solution {
public:
  long long shiftDistance(string s, string t, vector<int> &nextCost,
                          vector<int> &previousCost) {
    int n = s.size();

    auto GetNextCost = [&](int x, int y) -> int64 {
      if (x == y)
        return 0;
      else if (x < y)
        return accumulate(nextCost.begin() + x, nextCost.begin() + y, 0LL);
      else
        return accumulate(nextCost.begin() + x, nextCost.end(), 0LL) +
               accumulate(nextCost.begin(), nextCost.begin() + y, 0LL);
    };

    auto GetPrevCost = [&](int x, int y) -> int64 {
      if (x == y)
        return 0;
      else if (y < x)
        return accumulate(previousCost.begin() + y + 1,
                          previousCost.begin() + x + 1, 0LL);
      else
        return accumulate(previousCost.begin(), previousCost.begin() + x + 1,
                          0LL) +
               accumulate(previousCost.begin() + y + 1, previousCost.end(),
                          0LL);
    };

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int x = s[i] - 'a', y = t[i] - 'a';
      ans += min(GetNextCost(x, y), GetPrevCost(x, y));
    }
    return ans;
  }
};
