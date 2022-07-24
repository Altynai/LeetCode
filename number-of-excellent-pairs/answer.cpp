#define bitCount(n) __builtin_popcountll((n))

template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  long long countExcellentPairs(vector<int> &a, int k) {
    long long ans = 0;
    deduplicate(a);
    vector<int> cnt(k + 1, 0);
    for (int x : a) {
      int p = bitCount(x);
      if (p * 2 >= k)
        ans++;
      for (int i = max(k - p, 0); i <= k; i++)
        ans += cnt[i] * 2;
      cnt[min(p, k)]++;
    }
    return ans;
  }
};
