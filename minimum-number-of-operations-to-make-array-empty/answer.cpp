class Solution {
public:
  int minOperations(vector<int> &a) {
    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    int ans = 0;
    for (auto [_, cnt] : freq) {
      if (cnt == 1)
        return -1;

      if (cnt % 3 == 0)
        ans += cnt / 3;
      else if (cnt % 3 == 2)
        ans += cnt / 3 + 1;
      else
        ans += (cnt - 3) / 3 + 2;
    }
    return ans;
  }
};
