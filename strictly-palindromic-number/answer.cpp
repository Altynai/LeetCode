class Solution {
public:
  bool isStrictlyPalindromic(int n) {
    for (int i = 2; i <= n - 2; i++) {
      vector<int> p;
      for (int x = n; x > 0; x /= i)
        p.push_back(x % i);
      vector<int> q = p;
      reverse(q.begin(), q.end());
      if (p != q)
        return false;
    }
    return true;
  }
};
