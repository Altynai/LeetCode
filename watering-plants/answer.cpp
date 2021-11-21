class Solution {
public:
  int wateringPlants(vector<int> &a, int cap) {
    int n = a.size(), ans = 0, now = cap;
    for (int i = 0; i < n; i++) {
      if (now < a[i]) {
        ans += i * 2;
        now = cap;
      }
      ans++;
      now -= a[i];
    }
    return ans;
  }
};
