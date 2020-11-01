class Solution {
public:
  int furthestBuilding(vector<int> &h, int b, int l) {
    int n = h.size();
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i + 1 < n; i++) {
      if (h[i + 1] > h[i])
        q.push(h[i + 1] - h[i]);
      if (q.size() > l) {
        int d = q.top();
        q.pop();
        b -= d;
        if (b < 0)
          return i;
      }
    }
    return n - 1;
  }
};
