using int64 = long long;

class Solution {
public:
  int maxIncreasingGroups(vector<int> &a) {
    int n = a.size(), k = 0;
    sort(a.begin(), a.end());

    int64 sum = 0;
    for (int x : a) {
      sum += x;
      if (sum >= 1LL * (k + 1) * (k + 2) / 2)
        k++;
    }
    return k;
  }
};
