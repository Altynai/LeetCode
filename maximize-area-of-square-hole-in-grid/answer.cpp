class Solution {
private:
  int longest(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int i = 0, ans = 1, len = 1;
    for (i = 1; i < n; i++) {
      if (a[i] == a[i - 1] + 1)
        ans = max(ans, ++len);
      else
        len = 1;
    }
    return ans;
  }

public:
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                             vector<int> &vBars) {
    int k = min(longest(hBars), longest(vBars)) + 1;
    return k * k;
  }
};

