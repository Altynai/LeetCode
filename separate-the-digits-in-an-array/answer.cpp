class Solution {
public:
  vector<int> separateDigits(vector<int> &a) {
    vector<int> b;
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      while (x > 0)
        b.push_back(x % 10), x /= 10;
    }
    reverse(b.begin(), b.end());
    return b;
  }
};
