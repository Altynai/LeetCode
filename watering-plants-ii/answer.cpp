class Solution {
public:
  int minimumRefill(vector<int> &p, int A, int B) {
    int ans = 0, a = A, b = B;
    for (int i = 0, j = p.size() - 1; i <= j; i++, j--) {
      if (i == j) {
        if (max(a, b) < p[i])
          ans++;
      } else {
        if (a < p[i])
          ans++, a = A - p[i];
        else
          a -= p[i];

        if (b < p[j])
          ans++, b = B - p[j];
        else
          b -= p[j];
      }
    }
    return ans;
  }
};
