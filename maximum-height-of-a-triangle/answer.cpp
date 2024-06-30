class Solution {
public:
  int maxHeightOfTriangle(int red, int blue) {
    return max(maxHeight(red, blue), maxHeight(blue, red));
  }

  int maxHeight(int a, int b) {
    vector<int> cnt = {a, b};
    int ans = 0, p = 0;
    while (cnt[p] >= ans + 1) {
      ans++;
      cnt[p] -= ans;
      p ^= 1;
    }
    return ans;
  }
};
