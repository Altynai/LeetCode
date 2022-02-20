class Solution {
public:
  vector<long long> maximumEvenSplit(long long x) {
    if (x % 2 == 1)
      return {};

    vector<long long> ans;
    for (int k = 2; x >= k; k += 2) {
      ans.push_back(k);
      x -= k;
    }
    ans.back() += x;
    return ans;
  }
};
