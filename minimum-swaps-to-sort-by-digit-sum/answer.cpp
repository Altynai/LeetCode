class Solution {

  int sum(int x) {
    int res = 0;
    while (x > 0) {
      res += x % 10;
      x /= 10;
    }
    return res;
  }

public:
  int minSwaps(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> v(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
      v[i] = {sum(a[i]), a[i]};
      pos[a[i]] = i;
    }

    sort(v.begin(), v.end());
    unordered_set<int> seen;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == v[i].second)
        continue;
      // x y .. z
      // y z .. x
      if (seen.count(a[i]))
        continue;

      int x = a[i], y = v[i].second;
      seen.insert(x);
      int cnt = 1;
      while (seen.count(y) == 0) {
        seen.insert(y);
        cnt++;
        x = y;
        int j = pos[y];
        y = v[j].second;
      }
      ans += cnt - 1;
    }
    return ans;
  }
};
