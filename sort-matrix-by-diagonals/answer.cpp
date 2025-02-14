class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &a) {
    int n = a.size();

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
      int m = 0;
      for (int x = i, y = 0; x < n; x++, y++)
        p[m++] = a[x][y];
      sort(p.begin(), p.begin() + m);
      reverse(p.begin(), p.begin() + m);
      m = 0;
      for (int x = i, y = 0; x < n; x++, y++)
        a[x][y] = p[m++];
    }

    for (int j = 1; j < n; j++) {
      int m = 0;
      for (int x = 0, y = j; y < n; x++, y++)
        p[m++] = a[x][y];
      sort(p.begin(), p.begin() + m);
      m = 0;
      for (int x = 0, y = j; y < n; x++, y++)
        a[x][y] = p[m++];
    }
    return a;
  }
};
