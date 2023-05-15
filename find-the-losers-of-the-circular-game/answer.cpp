class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<int> times(n, 0);
    int x = 0, i = 1;
    while (times[x] == 0) {
      times[x]++;
      x += (i * k);
      x %= n;
      i++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (times[i] == 0)
        ans.push_back(i + 1);
    }
    return ans;
  }
};
