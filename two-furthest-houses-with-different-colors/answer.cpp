class Solution {
public:
  int maxDistance(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] != a[j])
          ans = max(ans, j - i);
    return ans;
  }
};
