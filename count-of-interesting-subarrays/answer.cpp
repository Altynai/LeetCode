using int64 = long long;

class Solution {
public:
  long long countInterestingSubarrays(vector<int> &a, int modulo, int k) {
    int n = a.size();
    unordered_map<int, int> cnt;
    cnt[0] = 1;

    int sum = 0;
    int64 ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i - 1] % modulo == k)
        sum++;
      if (i >= k) {
        int x = sum % modulo;
        int y = (x >= k ? x - k : x - k + modulo);
        auto it = cnt.find(y);
        if (it != cnt.end())
          ans += it->second;
      }
      cnt[sum % modulo]++;
    }
    return ans;
  }
};
