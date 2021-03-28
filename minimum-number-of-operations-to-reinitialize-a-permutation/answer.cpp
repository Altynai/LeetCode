class Solution {
public:
  int reinitializePermutation(int n) {
    auto is_valid = [&](vector<int> &p) -> bool {
      for (int i = 0; i < n; i++)
        if (p[i] != i)
          return 0;
      return 1;
    };

    auto trans = [&](vector<int> &p) {
      vector<int> arr(n);
      for (int i = 0; i < n; i++) {
        if (i & 1)
          arr[i] = p[n / 2 + (i - 1) / 2];
        else
          arr[i] = p[i / 2];
      }
      for (int i = 0; i < n; i++)
        p[i] = arr[i];
    };

    vector<int> p(n);
    for (int i = 0; i < n; i++)
      p[i] = i;

    int ans = 0;
    do {
      trans(p);
      ans++;
    } while (!is_valid(p));
    return ans;
  }
};
