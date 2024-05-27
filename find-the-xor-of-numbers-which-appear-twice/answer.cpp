class Solution {
public:
  int duplicateNumbersXOR(vector<int> &a) {
    unordered_map<int, int> freq;
    int ans = 0;
    for (int x : a) {
      if (++freq[x] == 2)
        ans ^= x;
    }
    return ans;
  }
};
