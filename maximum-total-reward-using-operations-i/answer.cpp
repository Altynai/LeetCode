const int N = 4e3 + 3;

class Solution {
public:
  int maxTotalReward(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size(), MAX = a[n - 1];

    bitset<N> bs(0);
    bs[0] = 1;
    for (int i = 0; i < n; i++) {
      // we need to ignore bits [a[i] ... N - 1]
      bitset<N> mask = (bs << (N - a[i])) >> (N - a[i]);
      bs |= (mask << a[i]);
    }

    for (int i = MAX * 2; i >= 0; i--) {
      if (bs[i] == 1)
        return i;
    }
    return -1;
  }
};
