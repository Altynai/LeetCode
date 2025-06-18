template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maximumProduct(vector<int> &a, int m) {
    int n = a.size();
    int64 ans = LLONG_MIN;
    multiset<int> s(a.begin() + m - 1, a.end());
    for (int i = 0; i + m <= n; i++) {
      umax(ans, 1LL * a[i] * (*s.begin()));
      umax(ans, 1LL * a[i] * (*prev(s.end())));
      s.erase(s.find(a[i + m - 1]));
    }
    return ans;
  }
};
