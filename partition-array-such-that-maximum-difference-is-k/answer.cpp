class Solution {
public:
  int partitionArray(vector<int> &a, int k) {
    sort(a.begin(), a.end());
    int n = a.size(), ans = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and a[j] - a[i] <= k)
        j++;
      ans++;
      i = j;
    }
    return ans;
  }
};
