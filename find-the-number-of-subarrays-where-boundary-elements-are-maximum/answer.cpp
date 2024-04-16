using int64 = long long;

struct RMQ {
  typedef int T;

  const static int N = 100002;
  const static int M = 17; // 2^M >= N

  T ma[N][M];

  void init(int n, const vector<T> &val) {
    for (int i = 0; i < n; i++) {
      ma[i][0] = val[i];
    }

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T getMax(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return max(ma[a][k], ma[b - (1 << k) + 1][k]);
  }
} rmq;

class Solution {
public:
  long long numberOfSubarrays(vector<int> &a) {
    int n = a.size();
    rmq.init(n, a);

    unordered_map<int, vector<int>> where;
    for (int i = 0; i < n; i++)
      where[a[i]].push_back(i);

    int64 ans = n;
    for (auto &[x, pos] : where) {
      int m = pos.size();
      for (int i = 0; i + 1 < m;) {
        int j = i + 1;
        while (j < m and rmq.getMax(pos[j - 1], pos[j]) == a[pos[j]])
          j++;
        int cnt = j - i;
        ans += 1LL * cnt * (cnt - 1) / 2;
        i = j;
      }
    }
    return ans;
  }
};
