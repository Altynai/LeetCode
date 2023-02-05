class Solution {
public:
  long long pickGifts(vector<int> &a, int k) {
    int n = a.size();
    for (int i = 0; i < k; i++) {
      sort(a.begin(), a.end());
      if (a[n - 1] == 0)
        break;
      a[n - 1] = (int)floor(sqrt(1.0 * a[n - 1]));
    }
    return accumulate(a.begin(), a.end(), 0LL);
  }
};
