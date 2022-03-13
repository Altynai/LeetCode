class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &a, int key, int k) {
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      bool found = 0;
      for (int j = max(i - k, 0); !found and j <= min(n - 1, i + k); j++)
        found = (found or a[j] == key);
      if (found)
        ans.push_back(i);
    }
    return ans;
  }
};
