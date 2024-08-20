class Solution {
public:
  vector<int> resultsArray(vector<int> &a, int k) {
    int n = a.size();

    vector<int> ans(n - k + 1, -1);
    for (int i = 0; i < n;) {
      int j = i;
      while (j + 1 < n and a[j + 1] == a[j] + 1)
        j++;
      if (j - i + 1 >= k) {
        for (int x = i + k - 1; x <= j; x++)
          ans[x - (k - 1)] = a[x];
      }
      i = j + 1;
    }
    return ans;
  }
};
