class Solution {
public:
  int countHillValley(vector<int> &a) {
    int n = a.size(), m = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[m - 1])
        a[m++] = a[i];
    }
    a.resize(m);
    n = m;

    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
      if (a[i - 1] > a[i] and a[i] < a[i + 1])
        ans++;
      else if (a[i - 1] < a[i] and a[i] > a[i + 1])
        ans++;
    }
    return ans;
  }
};
