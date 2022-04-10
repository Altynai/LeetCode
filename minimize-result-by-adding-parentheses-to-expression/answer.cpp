class Solution {
public:
  string minimizeResult(string s) {
    int plus = s.find('+'), n = s.size();

    long long best = LLONG_MAX;
    int l = -1, r = -1;

    for (int i = plus - 1; i >= 0; i--) {
      int a = (i > 0 ? stoi(s.substr(0, i)) : 1);
      int b = stoi(s.substr(i, plus - i));
      for (int j = plus + 1; j < n; j++) {
        int c = stoi(s.substr(plus + 1, j - plus));
        int d = (j + 1 < n ? stoi(s.substr(j + 1, n - j)) : 1);
        long long val = 1LL * a * (b + c) * d;
        if (val < best) {
          best = val;
          l = i, r = j;
        }
      }
    }

    s.insert(s.begin() + r + 1, ')');
    s.insert(s.begin() + l, '(');
    return s;
  }
};
