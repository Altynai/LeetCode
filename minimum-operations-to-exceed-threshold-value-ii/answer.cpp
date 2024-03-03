using int64 = long long;

class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    multiset<int64> s(a.begin(), a.end());

    int64 _k = k;
    while (s.size() >= 2 and *s.begin() < _k) {
      int64 x = *s.begin();
      s.erase(s.begin());
      int64 y = *s.begin();
      s.erase(s.begin());
      s.insert(min(x, y) * 2 + max(x, y));
      ans++;
    }
    return ans;
  }
};
