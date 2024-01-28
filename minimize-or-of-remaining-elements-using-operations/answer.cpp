const int N = 30;

class Solution {
public:
  int minOrAfterOperations(vector<int> &a, int k) {
    int ans = 0, n = a.size();
    for (int i = N - 1; i >= 0; i--) {
      int zeroCnt = 0;
      int rangeAdd = (1 << N) - 1;
      // formed with format: ans + 0 + 111111
      // because we wish to unset i-th bit and also keep the previous state
      // (i.e. ans)
      int wantedState = ans | ((1 << i) - 1);
      for (int x : a) {
        rangeAdd &= x;
        // we set [i + 1, n - 1] bits to 1 in `wantedState`
        // which simplifies the following OR checking

        // if rangeAdd's i-th bit is set, then the following OR checking is
        // false
        if ((rangeAdd | wantedState) == wantedState) {
          zeroCnt++;
          rangeAdd = (1 << N) - 1;
        }
      }
      if (n - zeroCnt > k)
        ans |= (1 << i);
    }
    return ans;
  }
};
