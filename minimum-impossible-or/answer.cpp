template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  int minImpossibleOR(vector<int> &a) {
    int n = deduplicate(a);
    int ans = 1;

    auto Test = [&](int x) -> bool {
      int res = 0;
      for (int i = 0; i < n and a[i] <= x; i++) {
        if ((x & a[i]) == a[i])
          res |= a[i];
      }
      return res == x;
    };

    while (Test(ans))
      ans *= 2;
    return ans;
  }
};
