class Solution {
public:
  int countSubarrays(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    int pos = find(a.begin(), a.end(), k) - a.begin() + 1;

    map<int, int> cnt;
    cnt[0] = 1;
    for (int i = 1, sum = 0; i <= n; i++) {
      if (a[i - 1] > k)
        sum++;
      else if (a[i - 1] < k)
        sum--;

      if (i >= pos)
        ans += cnt[sum] + cnt[sum - 1];
      if (i < pos)
        cnt[sum]++;
    }
    return ans;
  }
};
