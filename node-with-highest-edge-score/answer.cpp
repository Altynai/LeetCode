using int64 = long long;

class Solution {
public:
  int edgeScore(vector<int> &a) {
    int n = a.size();
    vector<int64> sum(n, 0);
    for (int i = 0; i < n; i++)
      sum[a[i]] += i;
    int p = 0;
    for (int i = 1; i < n; i++) {
      if (sum[i] > sum[p])
        p = i;
    }
    return p;
  }
};
