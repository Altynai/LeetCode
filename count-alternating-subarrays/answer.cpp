using int64 = long long;

class Solution {
public:
  long long countAlternatingSubarrays(vector<int> &a) {
    int n = a.size();
    int64 ans = n;
    for (int i = 0; i < n;) {
      int j = i + 1;
      // only count len >= 2
      while (j < n and a[j] == (a[j - 1] ^ 1))
        j++;

      int64 len = j - i;
      ans += len * (len - 1) / 2;
      i = j;
    }
    return ans;
  }
};
