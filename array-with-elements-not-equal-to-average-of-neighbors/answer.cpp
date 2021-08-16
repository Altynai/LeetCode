class Solution {
public:
  vector<int> rearrangeArray(vector<int> &a) {
    sort(a.begin(), a.end());
    vector b = a;
    int i = 0, n = a.size();
    for (int j = 0; j < n; j += 2)
      b[j] = a[i++];
    for (int j = 1; j < n; j += 2)
      b[j] = a[i++];
    return b;
  }
};
