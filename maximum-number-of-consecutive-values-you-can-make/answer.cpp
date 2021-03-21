class Solution {
public:
  int getMaximumConsecutive(vector<int> &coins) {
    sort(coins.begin(), coins.end());

    int res = 1;
    for (int c : coins) {
      if (c > res)
        break;
      res += c;
    }
    return res;
  }
};
