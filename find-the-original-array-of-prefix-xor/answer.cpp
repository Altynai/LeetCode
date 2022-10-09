class Solution {
public:
  vector<int> findArray(vector<int> &p) {
    int n = p.size();
    vector<int> a(n, p[0]);
    for (int i = 1; i < n; i++)
      a[i] = p[i] ^ p[i - 1];
    return a;
  }
};
