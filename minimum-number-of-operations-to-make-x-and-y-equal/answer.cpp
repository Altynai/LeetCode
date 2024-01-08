class Solution {
public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x == y)
      return 0;

    const int N = max(x, y) * 11 + 1;

    vector<int> dis(N, INT_MAX);
    queue<int> que;

    dis[x] = 0;
    que.push(x);

    auto Transfer = [&](int z, int d) {
      if (dis[z] > d) {
        dis[z] = d;
        que.push(z);
      }
    };

    while (!que.empty()) {
      int z = que.front();
      que.pop();

      if (z % 11 == 0)
        Transfer(z / 11, dis[z] + 1);
      if (z % 5 == 0)
        Transfer(z / 5, dis[z] + 1);
      if (z + 1 < N)
        Transfer(z + 1, dis[z] + 1);
      if (z > 1)
        Transfer(z - 1, dis[z] + 1);
    }
    return dis[y];
  }
};
