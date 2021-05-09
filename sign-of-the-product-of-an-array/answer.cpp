class Solution {
public:
  int arraySign(vector<int> &nums) {
    int neg = 0;
    for (int num : nums) {
      if (num == 0)
        return 0;
      if (num < 0)
        neg = (neg + 1) % 2;
    }
    return neg ? -1 : 1;
  }
};
