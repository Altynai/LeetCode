class Solution {
public:
  int minOperations(vector<int> &a, vector<int> &b) {
    int g = 0;
    for (int x : b)
      g = gcd(x, g);

    int n = a.size();
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (g % a[i] == 0)
        return i;
    }
    return -1;
  }
};
