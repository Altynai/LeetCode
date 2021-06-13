class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &a, vector<int> &b) {
    vector<int> best(3, 0);
    for (vector<int> &each : a) {
      if (each[0] <= b[0] && each[1] <= b[1] && each[2] <= b[2]) {
        for (int i = 0; i < 3; i++)
          best[i] = max(best[i], each[i]);
      }
    }
    return best == b;
  }
};
