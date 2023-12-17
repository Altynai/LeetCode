using int64 = long long;

class Solution {
public:
  long long minimumCost(vector<int> &a) {
    int n = a.size();

    auto Cost = [&](int64 p) -> int64 {
      int64 res = 0;
      for (int x : a)
        res += llabs(p - x);
      return res;
    };

    auto NextNumber = [](int x) -> int {
      string s = to_string(x);
      int m = s.size();

      int i = 0, j = m - 1;
      while (i < j)
        s[j--] = s[i++];

      int y = stoi(s);
      if (y >= x)
        return y;

      // odd string
      if (i == j) {
        y = stoi(s.substr(0, i + 1)) + 1;
        string t = to_string(y);
        for (int k = t.size() - 2; k >= 0; k--)
          t.push_back(t[k]);
        return stoi(t);
      }
      // even string
      else {
        assert(j + 1 == i);
        y = stoi(s.substr(0, j + 1)) + 1;
        string t = to_string(y);
        for (int k = j; k >= 0; k--)
          t.push_back(t[k]);
        return stoi(t);
      }
    };

    auto PrevNumber = [](int x) -> int {
      string s = to_string(x);
      int m = s.size();

      int i = 0, j = m - 1;
      while (i < j)
        s[j--] = s[i++];

      int y = stoi(s);
      if (y < x)
        return y;

      // odd string
      if (i == j) {
        int y = stoi(s.substr(0, i + 1)) - 1;
        string t = to_string(y);
        // edge case: 10000 -> 9999
        if (t.size() == m / 2) {
          t = string(m - 1, '9');
        } else {
          for (int k = t.size() - 2; k >= 0; k--)
            t.push_back(t[k]);
        }
        return stoi(t);
      }
      // even string
      else {
        assert(j + 1 == i);
        int y = stoi(s.substr(0, j + 1)) - 1;
        string t = to_string(y);
        // edge case: 1000 -> 999
        if (t.size() == m / 2 - 1) {
          t = string(m - 1, '9');
        } else {
          for (int k = t.size() - 1; k >= 0; k--)
            t.push_back(t[k]);
        }
        return stoi(t);
      }
    };

    sort(a.begin(), a.end());
    int middle = (n % 2 == 0 ? (a[n / 2] + a[n / 2 - 1]) / 2 : a[n / 2]);
    return min(Cost(NextNumber(middle)), Cost(PrevNumber(middle)));
  }
};
