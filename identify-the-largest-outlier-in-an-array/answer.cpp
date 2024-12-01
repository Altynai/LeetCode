class Solution {
public:
  int getLargestOutlier(vector<int> &a) {
    int sum = accumulate(a.begin(), a.end(), 0);
    int n = a.size();
    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    int ans = INT_MIN;
    for (int outlier : a) {
      int s = sum - outlier;
      if (s % 2 != 0)
        continue;
      auto it = freq.find(s / 2);
      if (it == freq.end())
        continue;
      auto [k, v] = *it;
      if (k != outlier or v > 1)
        ans = max(ans, outlier);
    }
    return ans;
  }
};
