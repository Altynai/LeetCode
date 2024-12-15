/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
template <class InputIt> vector<int> z_function(InputIt begin, InputIt end) {
  int n = (int)distance(begin, end);
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && *(begin + z[i]) == *(begin + i + z[i]))
        ++z[i];
    }
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

class Solution {
public:
  int beautifulSplits(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> lcp(n);
    for (int i = 0; i < n - 1; i++)
      lcp[i] = z_function(a.begin() + i, a.end());

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        // nums1: a[0 ... i]
        // nums2: a[i+1 ... j]
        // nums3: a[j+1 ... n-1]

        int len1 = i + 1, len2 = j - i, len3 = n - (j + 1);

        // nums1 is a prefix of nums2
        if (len2 >= len1 and lcp[0][i + 1] >= len1) {
          ans++;
          continue;
        }

        // nums2 is a prefix of nums3
        if (len3 >= len2 and lcp[i + 1][j - i] >= len2)
          ans++;
      }
    }
    return ans;
  }
};
