class Solution {
public:
  int findMiddleIndex(vector<int> &a) {
    int n = a.size(), sum = accumulate(a.begin(), a.end(), 0), now = 0;
    for (int i = 0; i < n; i++) {
      if (now == sum - now - a[i])
        return i;
      now += a[i];
    }
    return -1;
  }
};
