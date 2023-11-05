class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    vector<int> deg(n);
    for (auto &e : edges)
      deg[e[1]]++;

    int p = -1;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        if (p == -1)
          p = i;
        else
          return -1;
      }
    }
    return p;
  }
};
