class Solution {
public:
  int minimumRightShifts(vector<int> &a) {
    int n = a.size(), pos = min_element(a.begin(), a.end()) - a.begin();
    for (int i = (pos + 1) % n; i != pos; i = (i + 1) % n) {
      if (a[i] < a[(i - 1 + n) % n])
        return -1;
    }
    return (pos == 0 ? 0 : n - pos);
  }
};
