class Solution {
public:
  int bestRotation(vector<int> &a) {
    int n = a.size();
    vector<int> p(n + 1, 0);

    auto add_segment = [&](int l, int r) {
      assert(l <= r);
      p[l]++;
      p[r + 1]--;
    };

    for (int i = 0; i < n; i++) {
      // a[i]'s valid range: (a[i], n - 1)
      if (a[i] == i) {
        add_segment(0, 0);
        if (i < n - 1)
          add_segment(i + 1, n - 1);
      } else if (a[i] < i) {
        add_segment(0, i - a[i]);
        if (i < n - 1)
          add_segment(i + 1, n - 1);
      } else {
        int d = n - a[i];
        add_segment(i + 1, i + d);
      }
    }

    int ans = -1, k = -1;
    for (int i = 0; i < n; i++) {
      if (i > 0)
        p[i] += p[i - 1];
      if (p[i] > ans)
        ans = p[i], k = i;
    }
    return k;
  }
};
