class Solution {
public:
  vector<vector<int>> resultGrid(vector<vector<int>> &img, int threshold) {
    int n = img.size(), m = img[0].size();
    vector<vector<int>> sum(n, vector<int>(m, 0)), cnt(n, vector<int>(m, 0));

    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m - 2; j++) {

        bool good = 1;
        for (int x = 0; good and x <= 2; x++) {
          for (int y = 0; good and y <= 2; y++) {
            // right
            if (y <= 1 and
                abs(img[i + x][j + y] - img[i + x][j + y + 1]) > threshold)
              good = 0;
            // down
            if (x <= 1 and
                abs(img[i + x][j + y] - img[i + x + 1][j + y]) > threshold)
              good = 0;
          }
        }

        if (good) {
          int total = 0;
          for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++)
              total += img[i + x][j + y];
          }
          for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++) {
              sum[i + x][j + y] += total / 9;
              cnt[i + x][j + y]++;
            }
          }
        }
      }
    }

    vector<vector<int>> ans = img;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (cnt[i][j] > 0)
          ans[i][j] = sum[i][j] / cnt[i][j];
      }
    }
    return ans;
  }
};
