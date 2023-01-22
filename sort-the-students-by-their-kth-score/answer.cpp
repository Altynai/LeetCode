class Solution {
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &s, int k) {
    sort(s.begin(), s.end(),
         [&](const auto &lh, const auto &rh) { return lh[k] > rh[k]; });
    return s;
  }
};
