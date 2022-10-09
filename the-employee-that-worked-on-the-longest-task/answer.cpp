class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int tm = 0, m = logs.size();
    int longest = 0, id = n;
    for (int i = 0; i < m; i++) {
      int len = logs[i][1] - tm;
      if (len > longest or (longest == len and logs[i][0] < id)) {
        longest = len;
        id = logs[i][0];
      }
      tm = logs[i][1];
    }
    return id;
  }
};
