class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>> &events) {
    int n = events.size();
    int t = events[0][1], index = events[0][0];
    for (int i = 1; i < n; i++) {
      int dt = events[i][1] - events[i - 1][1];
      if (dt > t or (dt == t and events[i][0] < index))
        t = dt, index = events[i][0];
    }
    return index;
  }
};
