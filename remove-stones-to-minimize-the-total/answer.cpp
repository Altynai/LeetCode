class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    multiset<int> s(piles.begin(), piles.end());
    int sum = accumulate(piles.begin(), piles.end(), 0);
    while (k--) {
      auto it = prev(s.end());
      int val = *it;
      if (val == 1)
        break;
      sum -= val / 2;
      s.erase(it);
      s.emplace(val - val / 2);
    }
    return sum;
  }
};
