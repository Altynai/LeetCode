class Solution {
public:
  int scheduleCourse(vector<vector<int>> &a) {
    int n = a.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) {
      if (a[x][1] != a[y][1])
        return a[x][1] < a[y][1];
      return a[x][0] < a[y][0];
    });

    priority_queue<int> best;
    int day = 1;
    for (int i = 0; i < n; i++) {
      int dur = a[p[i]][0], last = a[p[i]][1];
      if (day + dur - 1 <= last) {
        best.push(dur);
        day += dur;
      } else if (!best.empty() and best.top() > dur) {
        day -= best.top();
        best.pop();
        best.push(dur);
        day += dur;
      }
    }
    return best.size();
  }
};
