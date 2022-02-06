class Solution {
public:
  vector<int> sortEvenOdd(vector<int> &a) {
    int n = a.size();
    for (int x = 0; x <= 1; x++) {
      vector<int> p;
      for (int i = x; i < n; i += 2)
        p.push_back(a[i]);

      sort(p.begin(), p.end());
      if (x == 1)
        reverse(p.begin(), p.end());

      for (int i = x, j = 0; i < n; i += 2)
        a[i] = p[j++];
    }
    return a;
  }
};
