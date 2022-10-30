class Solution {
public:
  vector<string> twoEditWords(vector<string> &q, vector<string> &d) {
    int n = q.size(), m = d.size();
    vector<string> ans;

    for (int i = 0; i < n; i++) {
      int sz = q[i].size();
      bool found = 0;
      for (int j = 0; !found and j < m; j++) {
        int cnt = 0;
        for (int k = 0; k < sz; k++) {
          if (q[i][k] != d[j][k])
            cnt++;
        }
        if (cnt <= 2)
          found = 1;
      }
      if (found)
        ans.push_back(q[i]);
    }
    return ans;
  }
};
