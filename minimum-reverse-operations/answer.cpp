class Solution {
public:
  vector<int> minReverseOperations(int n, int p, vector<int> &b, int k) {
    vector<bool> banned(n, 0);
    for (int x : b)
      banned[x] = 1;

    vector<set<int>> s(2);
    for (int i = 0; i < n; i++) {
      if (i != p and !banned[i])
        s[i & 1].insert(i);
    }

    vector<int> dis(n, -1);
    queue<int> que;
    que.push(p);
    dis[p] = 0;

    while (!que.empty()) {
      int x = que.front();
      que.pop();

      int l, r; // valid range for next jump points
      if (k & 1) {
        int pivot_lo = k / 2, pivot_hi = n - 1 - k / 2;
        pivot_lo = max(pivot_lo, x - k / 2);
        pivot_hi = min(pivot_hi, x + k / 2);
        // for any p in [pivot_lo, pivot_hi], the other point is p * 2 - x
        l = pivot_lo * 2 - x, r = pivot_hi * 2 - x;
      } else {
        int pivot_lo = k / 2 - 1, pivot_hi = n - 1 - k / 2;
        pivot_lo = max(pivot_lo, x - k / 2);
        pivot_hi = min(pivot_hi, x + k / 2 - 1);
        l = (pivot_lo * 2 + 1) - x, r = (pivot_hi * 2 + 1) - x;
      }

      auto it = s[l & 1].lower_bound(l);
      auto it2 = s[l & 1].upper_bound(r);
      while (it != it2) {
        int y = *it;
        if (dis[y] == -1) {
          dis[y] = dis[x] + 1;
          que.push(y);
        }
        it = s[l & 1].erase(it);
      }
    }
    return dis;
  }
};
