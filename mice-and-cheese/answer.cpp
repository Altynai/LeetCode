class Solution {
public:
  int miceAndCheese(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), sum = 0;
    for (int i = 0; i < n; i++)
      sum += b[i];

    vector<int> c(n);
    for (int i = 0; i < n; i++)
      c[i] = a[i] - b[i];
    sort(c.begin(), c.end());

    for (int i = 0; i < k; i++)
      sum += c[n - 1 - i];
    return sum;
  }
};
