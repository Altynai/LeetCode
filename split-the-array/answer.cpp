class Solution {
public:
  bool isPossibleToSplit(vector<int> &a) {
    unordered_map<int, int> cnt;
    for (int x : a) {
      if (++cnt[x] > 2)
        return 0;
    }
    return 1;
  }
};
