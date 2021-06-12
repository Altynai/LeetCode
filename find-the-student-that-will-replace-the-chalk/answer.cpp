class Solution {
public:
  int chalkReplacer(vector<int> &a, int k) {
    int n = a.size();
    long long s = 0;
    for (int val : a)
      s += val;

    long long m = 1LL * k % s;
    for (int i = 0; i < n; i++) {
      if (m < a[i])
        return i;
      m -= a[i];
    }
    return 0;
  }
};
