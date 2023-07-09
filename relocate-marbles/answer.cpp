class Solution {
public:
  vector<int> relocateMarbles(vector<int> &a, vector<int> &moveFrom,
                              vector<int> &moveTo) {
    set<int> b(a.begin(), a.end());
    int n = moveFrom.size();
    for (int i = 0; i < n; i++) {
      b.erase(b.find(moveFrom[i]));
      b.insert(moveTo[i]);
    }

    vector<int> ans(b.begin(), b.end());
    return ans;
  }
};
