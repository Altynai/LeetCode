class Solution {
public:
  vector<int> occurrencesOfElement(vector<int> &a, vector<int> &queries,
                                   int x) {
    vector<int> pos;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == x)
        pos.push_back(i);
    }

    int n = queries.size(), m = pos.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
      if (queries[i] <= m)
        ans[i] = pos[queries[i] - 1];
    }
    return ans;
  }
};
