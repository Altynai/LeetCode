class Solution {
public:
  int findTheWinner(int n, int k) {
    vector<bool> alive(n, true);
    int now = 0;
    for (int i = 0; i < n - 1; i++) {
      assert(alive[now]);
      int m = k - 1;
      while (m--) {
        now = (now + 1) % n;
        while (!alive[now])
          now = (now + 1) % n;
      }
      alive[now] = 0;
      // find next alive guy
      while (!alive[now])
        now = (now + 1) % n;
    }

    for (int i = 0; i < n; i++)
      if (alive[i])
        return i + 1;
    return -1;
  }
};
