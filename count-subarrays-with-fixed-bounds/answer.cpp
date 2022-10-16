class Solution {
public:
  long long countSubarrays(vector<int> &a, int minK, int maxK) {
    int n = a.size();
    int min_pos = -1, max_pos = -1, start = 0;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < minK or a[i] > maxK) {
        min_pos = max_pos = -1;
        start = i + 1;
        continue;
      }

      if (a[i] == minK)
        min_pos = i;
      if (a[i] == maxK)
        max_pos = i;

      if (min_pos != -1 and max_pos != -1)
        ans += min(min_pos, max_pos) - start + 1;
    }
    return ans;
  }
};
