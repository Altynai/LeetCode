class Solution {
public:
  int minOperations(vector<int> &a) {
    int ans = 0, n = a.size(), flip = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] ^ flip) == 1)
        continue;
      ans++, flip ^= 1;
    }
    return ans;
  }
};
