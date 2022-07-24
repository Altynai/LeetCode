class Solution {
public:
  long long zeroFilledSubarray(vector<int> &a) {
    int n = a.size();
    long long ans = 0;
    for (int i = 0; i < n;) {
      if (a[i] == 0) {
        int j = i;
        while (j < n and a[j] == 0)
          j++;
        long long len = j - i;
        ans += len * (len + 1) / 2;
        i = j;
      } else {
        i++;
      }
    }
    return ans;
  }
};
