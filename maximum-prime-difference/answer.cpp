const int N = 101;

class Solution {
public:
  int maximumPrimeDifference(vector<int> &a) {
    vector<bool> p(N, 1);
    p[1] = 0;
    for (int i = 4; i < N; i += 2)
      p[i] = 0;
    for (int i = 3; i < N; i++) {
      if (p[i]) {
        for (int j = i * i; j < N; j += i)
          p[j] = 0;
      }
    }

    int x = -1, y = -1, n = a.size();
    for (int i = 0; i < n; i++) {
      if (p[a[i]]) {
        if (x == -1)
          x = i;
        y = i;
      }
    }
    return y - x;
  }
};
