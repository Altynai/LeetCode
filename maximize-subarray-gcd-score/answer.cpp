template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maxGCDScore(vector<int> &a, int k) {
    int n = a.size();

    vector<int> twos(n, 0);
    for (int i = 0; i < n; i++) {
      while (a[i] > 0 and a[i] % 2 == 0) {
        twos[i]++;
        a[i] /= 2;
      }
    }

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      int g = a[i];
      map<int, int> freq;
      for (int j = i; j < n; j++) {
        g = gcd(g, a[j]);
        // we can at most double the gcd once
        freq[twos[j]]++;
        auto it = freq.begin();
        int p = it->first, cnt = it->second;
        if (k >= cnt)
          p++;
        umax(ans, 1LL * (j - i + 1) * g * (1 << p));
      }
    }
    return ans;
  }
};
