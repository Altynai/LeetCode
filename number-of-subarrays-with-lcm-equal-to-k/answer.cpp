class Solution {
public:
  int subarrayLCM(vector<int> &a, int k) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      int x = a[i];
      for (int j = i; x <= k and j < n; j++) {
        x = lcm(x, a[j]);
        if (x == k)
          ans++;
      }
    }
    return ans;
  }
};
