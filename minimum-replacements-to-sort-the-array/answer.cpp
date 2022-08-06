class Solution {
public:
  long long minimumReplacement(vector<int> &a) {
    int n = a.size();
    long long ans = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1]) {
        int div = a[i] / a[i + 1];
        int mod = a[i] % a[i + 1];
        if (mod == 0) {
          ans += div - 1;
          a[i] = a[i + 1];
        } else {
          ans += div;
          a[i] = a[i] / (div + 1);
        }
      }
    }
    return ans;
  }
};
