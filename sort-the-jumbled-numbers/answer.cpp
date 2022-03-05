class Solution {
public:
  vector<int> sortJumbled(vector<int> &m, vector<int> &a) {
    vector<pair<int, int>> pos;
    int n = a.size();
    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        pos.emplace_back(m[0], i);
      else {
        int val = 0;
        for (int x = a[i], ten = 1; x > 0; x /= 10, ten *= 10)
          val += ten * m[x % 10];
        pos.emplace_back(val, i);
      }
    }

    sort(pos.begin(), pos.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = a[pos[i].second];
    return ans;
  }
};
