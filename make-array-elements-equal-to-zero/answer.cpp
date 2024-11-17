class Solution {
public:
  int countValidSelections(vector<int> &a) {
    int n = a.size(), ans = 0;
    int sum = accumulate(a.begin(), a.end(), 0);
    for (int i = 0, prefix = 0; i < n; i++) {
      if (a[i] == 0) {
        if (prefix * 2 == sum)
          ans += 2;
        else if (abs(sum - prefix * 2) == 1)
          ans++;
      }
      prefix += a[i];
    }
    return ans;
  }
};
