class Solution {
public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ans = 0;
    for (int c = 0; c <= total; c += cost1)
      ans += (total - c) / cost2 + 1;
    return ans;
  }
};
