// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
// =====================================================================================================================

class Solution {
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
    int n = segments.size();
    int start = INT_MAX, end = INT_MIN;
    set<int> p;
    for (auto seg : segments) {
      umin(start, seg[0]);
      umax(end, seg[1]);
      p.insert(seg[0]);
      p.insert(seg[1]);
    }
    vector<long long> added(end + 1, 0LL);
    for (auto seg : segments) {
      added[seg[0]] += seg[2];
      added[seg[1]] -= seg[2];
    }
    for (int i = start; i <= end; i++)
      added[i] += added[i - 1];

    vector<vector<long long>> ans;
    vector<int> where(p.begin(), p.end());
    for (int i = 1; i < where.size(); i++) {
      if (added[where[i - 1]] > 0)
        ans.push_back({where[i - 1], where[i], added[where[i - 1]]});
    }
    return ans;
  }
};
