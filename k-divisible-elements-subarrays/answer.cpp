const int P = 962592769;
const int Q = 31;
const int MOD = 1e9 + 7;

class Solution {
public:
  int countDistinct(vector<int> &a, int k, int p) {
    int n = a.size();
    set<pair<int, int>> ht;
    for (int i = 0; i < n; i++) {
      int hash_p = 0, hash_q = 0, cnt = 0;
      for (int j = i; j < n; j++) {
        if (a[j] % p == 0)
          cnt++;
        if (cnt > k)
          break;

        hash_p = (1LL * hash_p * P + a[j]) % MOD;
        hash_q = (1LL * hash_q * Q + a[j]) % MOD;
        ht.insert({hash_p, hash_q});
      }
    }
    return ht.size();
  }
};
