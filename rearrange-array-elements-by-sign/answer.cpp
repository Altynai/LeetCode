class Solution {
public:
  vector<int> rearrangeArray(vector<int> &a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0, j = 0, k = 0; k < n / 2; k++) {
      while (i < n and a[i] < 0)
        i++;
      b[k * 2] = a[i++];
      while (j < n and a[j] > 0)
        j++;
      b[k * 2 + 1] = a[j++];
    }
    return b;
  }
};
