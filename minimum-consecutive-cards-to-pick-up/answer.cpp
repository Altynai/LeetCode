class Solution {
public:
  int minimumCardPickup(vector<int> &a) {
    unordered_map<int, int> last;
    int ans = -1, n = a.size();
    for (int i = 0; i < n; i++) {
      auto it = last.find(a[i]);
      if (it != last.end()) {
        int len = i - (it->second) + 1;
        if (ans == -1 or len < ans)
          ans = len;
      }
      last[a[i]] = i;
    }
    return ans;
  }
};
