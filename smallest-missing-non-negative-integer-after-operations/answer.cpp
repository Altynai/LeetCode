class Solution {
public:
  int findSmallestInteger(vector<int> &a, int value) {
    unordered_map<int, int> cnt;
    for (int x : a)
      cnt[(x % value + value) % value]++;

    int mex = 0;
    while (cnt[mex % value] > 0) {
      cnt[mex % value]--;
      mex++;
    }
    return mex;
  }
};
