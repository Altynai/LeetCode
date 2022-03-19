class Solution {
public:
  bool divideArray(vector<int> &nums) {
    unordered_map<int, int> cnt;
    for (int x : nums)
      cnt[x]++;
    for (auto [x, c] : cnt)
      if (c & 1)
        return 0;
    return 1;
  }
};
