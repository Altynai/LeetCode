class Solution {
public:
  vector<vector<int>> divideArray(vector<int> &a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<vector<int>> ans;
    for (int i = 0; i < n; i += 3) {
      if (a[i + 2] - a[i] > k)
        return {};
      ans.push_back({a[i], a[i + 1], a[i + 2]});
    }
    return ans;
  }
};
