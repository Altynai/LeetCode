using int64 = long long;

class Solution {
public:
  long long maxArrayValue(vector<int> &a) {
    int n = a.size();
    stack<int64> s;
    int64 ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans = max(ans, 1LL * a[i]);
      if (!s.empty() and a[i] <= s.top()) {
        s.top() += a[i];
        ans = max(ans, s.top());
      } else
        s.push(a[i]);
    }
    return ans;
  }
};
