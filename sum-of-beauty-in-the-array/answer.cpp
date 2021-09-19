class Solution {
public:
  int sumOfBeauties(vector<int> &a) {
    int n = a.size();
    vector<int> mi(n);

    mi[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
      mi[i] = min(a[i], mi[i + 1]);

    int ans = 0, ma = a[0];
    for (int i = 1; i < n - 1; i++) {
      if (ma < a[i] && a[i] < mi[i + 1])
        ans += 2;
      else if (a[i - 1] < a[i] && a[i] < a[i + 1])
        ans += 1;
      ma = max(a[i], ma);
    }

    return ans;
  }
};
