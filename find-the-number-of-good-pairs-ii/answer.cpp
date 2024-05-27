using int64 = long long;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      unordered_map<int, int> freq;
      for (int x : nums2) freq[x]++;

      int64 ans = 0;
      for (int i = 0; i < n;i++) {
        if (nums1[i] % k == 0) {
          int x = nums1[i] / k;
          int sq = (int) sqrt(x * 1.0);
          for (int y = 1; y <= sq;y++) {
            if (x % y == 0) {
              auto it = freq.find(y);
              if (it != freq.end()) ans += it->second;
              int other = x / y;
              if (y != other) ans+= freq[other];
            }
          }
        }
      }
      return ans;
    }
};
