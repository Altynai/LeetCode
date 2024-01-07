class Solution {
public:
  int maximumSetSize(vector<int> &a, vector<int> &b) {
    int n = a.size();

    unordered_map<int, int> cnta, cntb;
    for (int x : a)
      cnta[x]++;
    for (int x : b)
      cntb[x]++;

    vector<int> common;
    for (auto [x, _] : cnta) {
      if (cntb.count(x))
        common.push_back(x);
    }

    int l = n / 2, r = n / 2;
    for (int x : common) {
      int d = min(cnta[x] - 1, l);
      cnta[x] -= d, l -= d;

      d = min(cntb[x] - 1, r);
      cntb[x] -= d, r -= d;
    }

    for (auto [x, y] : cnta) {
      int d = min(y - 1, l);
      cnta[x] -= d, l -= d;
    }
    for (auto [x, y] : cntb) {
      int d = min(y - 1, r);
      cntb[x] -= d, r -= d;
    }

    for (int x : common) {
      if (l > 0)
        cnta.erase(cnta.find(x)), l--;
    }
    while (l > 0)
      cnta.erase(cnta.begin()), l--;

    reverse(common.begin(), common.end());
    for (int x : common) {
      if (r > 0)
        cntb.erase(cntb.find(x)), r--;
    }
    while (r > 0)
      cntb.erase(cntb.begin()), r--;

    unordered_set<int> s;
    for (auto [x, _] : cnta)
      s.insert(x);
    for (auto [x, _] : cntb)
      s.insert(x);
    return s.size();
  }
};
