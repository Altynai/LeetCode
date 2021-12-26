class Solution {
public:
  bool isSameAfterReversals(int num) { return num == 0 or num % 10 > 0; }
};
