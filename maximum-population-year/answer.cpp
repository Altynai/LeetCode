class Solution {
public:
  int maximumPopulation(vector<vector<int>> &logs) {
    int year = 0, pop = 0;
    for (int i = 1950; i <= 2050; i++) {
      int cnt = 0;
      for (auto &log : logs) {
        if (log[0] <= i && i < log[1])
          cnt++;
      }
      if (cnt > pop) {
        pop = cnt;
        year = i;
      }
    }
    return year;
  }
};
