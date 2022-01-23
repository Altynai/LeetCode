class Solution {
public:
  int countElements(vector<int> &a) {
    sort(a.begin(), a.end());
    int ans = 0, n = a.size();
    for (int i = 1; i + 1 < n; i++) {
      if (a[i] > a[0] and a[i] < a[n - 1])
        ans++;
    }
    return ans;
  }
};
