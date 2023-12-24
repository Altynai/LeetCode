using int64 = long long;

const int MOD = 1e9 + 7;

class Solution {
public:
  int maximizeSquareArea(int n, int m, vector<int> &hFences,
                         vector<int> &vFences) {
    hFences.push_back(1);
    hFences.push_back(n);
    sort(hFences.begin(), hFences.end());

    vFences.push_back(1);
    vFences.push_back(m);
    sort(vFences.begin(), vFences.end());

    int h = hFences.size();
    unordered_set<int> hs;
    for (int i = 0; i < h; i++) {
      for (int j = i + 1; j < h; j++)
        hs.insert(hFences[j] - hFences[i]);
    }

    int r = -1;
    int v = vFences.size();
    for (int i = 0; i < v; i++) {
      for (int j = i + 1; j < v; j++) {
        int x = vFences[j] - vFences[i];
        if (hs.count(x))
          r = max(r, x);
      }
    }
    if (r == -1)
      return -1;
    return 1LL * r * r % MOD;
  }
};
