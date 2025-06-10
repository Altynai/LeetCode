using int64 = long long;

class Solution {
public:
  long long sumOfLargestPrimes(string word) {
    int n = word.size();
    set<int64> s;
    for (int i = 0; i < n; i++) {
      int64 val = 0;
      for (int j = i; j < n; j++) {
        val = val * 10 + (word[j] - '0');
        if (val == 1)
          continue;
        if (val > 2 and val % 2 == 0)
          continue;

        int m = (int)sqrt(val * 1.0);
        bool good = 1;
        for (int x = 2; good and x <= m; x++) {
          if (val % x == 0)
            good = 0;
        }
        if (good)
          s.insert(val);
        if (s.size() > 3)
          s.erase(s.begin());
      }
    }
    return accumulate(s.begin(), s.end(), 0LL);
  }
};
