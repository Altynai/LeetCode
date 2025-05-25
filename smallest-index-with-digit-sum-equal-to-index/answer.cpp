class Solution {
public:
  int smallestIndex(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int x = a[i]; x > 0; x /= 10)
        sum += x % 10;
      if (sum == i)
        return i;
    }
    return -1;
  }
};
