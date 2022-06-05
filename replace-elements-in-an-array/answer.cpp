class Solution {
public:
  vector<int> arrayChange(vector<int> &a, vector<vector<int>> &operations) {
    map<int, int> pos;
    int n = a.size();
    for (int i = 0; i < n; i++)
      pos[a[i]] = i;

    for (auto &op : operations) {
      pos[op[1]] = pos[op[0]];
      pos.erase(op[0]);
    }

    for (auto [val, idx] : pos)
      a[idx] = val;
    return a;
  }
};
