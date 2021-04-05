class Solution {
public:
  int countDifferentSubsequenceGCDs(vector<int> &a) {
    int mx = *max_element(a.begin(), a.end());
    vector<bool> had(mx + 1, false);
    for (int num : a)
      had[num] = 1;

    int ans = 0;
    for (int i = 1; i <= mx; i++) {
      int g = 0;
      for (int j = i; j <= mx; j += i) {
        if (had[j])
          g = gcd(j, g);
      }
      if (g == i)
        ans++;
    }
    return ans;
  }
};
