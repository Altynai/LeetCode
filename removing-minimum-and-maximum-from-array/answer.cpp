class Solution {
public:
  int minimumDeletions(vector<int> &a) {
    int i = min_element(a.begin(), a.end()) - a.begin();
    int j = max_element(a.begin(), a.end()) - a.begin();
    if (i > j)
      swap(i, j);
    int n = a.size();
    return min(min(j + 1, n - i), i + 1 + n - j);
  }
};
