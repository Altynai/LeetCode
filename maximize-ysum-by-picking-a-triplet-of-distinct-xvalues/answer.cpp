template <class T> bool umax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

class Solution {
public:
  int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
    int n = x.size();
    map<int, int> best;
    for (int i = 0; i < n; i++)
      umax(best[x[i]], y[i]);

    vector<int> v;
    for (auto [_, val] : best)
      v.push_back(val);

    int m = v.size();
    if (m < 3)
      return -1;

    sort(v.rbegin(), v.rend());
    return accumulate(v.begin(), v.begin() + 3, 0);
  }
};
