class Solution {
public:
  int getXORSum(vector<int> &a, vector<int> &b) {
    const int N = 30;

    auto countBit = [&](vector<int> &c) -> vector<int> {
      int n = c.size();
      vector<int> bs(N, 0);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
          if (c[i] & (1 << j))
            bs[j]++;
        }
      }
      return bs;
    };

    int n = a.size(), m = b.size();
    vector<int> bitA = countBit(a);
    vector<int> bitB = countBit(b);

    int ans = 0;
    for (int i = 0; i < N; i++) {
      long long cnt = 1LL * bitA[i] * bitB[i];
      if (cnt & 1)
        ans += (1 << i);
    }
    return ans;
  }
};
