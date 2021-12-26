class Solution {
public:
  vector<int> recoverArray(vector<int> &a) {
    int m = a.size();
    sort(a.begin(), a.end());

    for (int i = 1; i < m; i++) {
      int sum = a[0] + a[i];
      if (sum & 1)
        continue;

      int first = sum / 2;
      int k = first - a[0];
      if (k <= 0)
        continue;

      // try to validate k
      vector<bool> used(m, 0);
      vector<int> ans = {first};
      used[0] = used[i] = 1;

      for (int j = 0, p = 0; j < m; j++) {
        if (used[j])
          continue;
        int known = a[j] + k;
        while (p < m and a[p] <= known + k) {
          if (a[p] == known + k and !used[p]) {
            used[p++] = 1;
            ans.push_back(known);
            break;
          } else {
            p++;
          }
        }
      }
      if (ans.size() == m / 2)
        return ans;
    }
    return {};
  }
};
