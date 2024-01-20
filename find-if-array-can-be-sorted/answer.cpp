#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  bool canSortArray(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n;) {
      int j = i, bc = bitCount(a[i]);
      while (j < n and bc == bitCount(a[j]))
        j++;
      sort(a.begin() + i, a.begin() + j);
      i = j;
    }
    return is_sorted(a.begin(), a.end());
  }
};
