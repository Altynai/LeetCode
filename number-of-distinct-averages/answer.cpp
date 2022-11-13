class Solution {
public:
  int distinctAverages(vector<int> &a) {
    set<int> s;
    sort(a.begin(), a.end());
    for (int i = 0, j = a.size() - 1; i < j; i++, j--)
      s.insert(a[i] + a[j]);
    return s.size();
  }
}
