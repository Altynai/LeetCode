class Solution {
public:
  int similarPairs(vector<string> &words) {
    map<int, int> freq;
    for (auto &s : words) {
      int mask = 0;
      for (char c : s)
        mask |= 1 << (c - 'a');
      freq[mask]++;
    }

    int ans = 0;
    for (auto [k, v] : freq)
      ans += v * (v - 1) / 2;
    return ans;
  }
};
