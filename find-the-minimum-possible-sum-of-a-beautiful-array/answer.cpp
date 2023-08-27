using int64 = long long;

class Solution {
public:
  long long minimumPossibleSum(int n, int target) {
    unordered_set<int> seen;
    int64 sum = 0;
    for (int i = 1; n > 0; i++) {
      int j = target - i;
      if (j > 0 and seen.count(j))
        continue;

      n--, sum += i;
      seen.insert(i);
    }
    return sum;
  }
};
