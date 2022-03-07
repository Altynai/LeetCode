class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    int n = profits.size();

    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int x, int y) {
      if (capital[x] != capital[y])
        return capital[x] < capital[y];
      else
        return profits[x] > profits[y];
    });

    priority_queue<int> que;
    for (int i = 0, j = 0; i < k; i++) {
      while (j < n and w >= capital[ids[j]]) {
        que.push(profits[ids[j]]);
        j++;
      }
      if (que.empty())
        break;

      w += que.top();
      que.pop();
    }
    return w;
  }
};
