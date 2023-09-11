const int N = 101;

class Solution {
public:
  int numberOfPoints(vector<vector<int>> &a) {
    vector<int> vis(N, 0);
    for (auto &v : a) {
      for (int i = v[0]; i <= v[1]; i++)
        vis[i] = 1;
    }
    return accumulate(vis.begin(), vis.end(), 0);
  }
};
