class Solution {
public:
  vector<int> targetIndices(vector<int> &a, int target) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (a[i] == target)
        ans.push_back(i);
    }
    return ans;
  }
};
