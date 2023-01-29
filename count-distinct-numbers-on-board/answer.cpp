class Solution {
public:
  int distinctIntegers(int n) {
    set<int> a = {n};
    while (true) {
      vector<int> b;
      for (int x : a) {
        for (int i = 1; i <= n; i++) {
          if (x % i == 1 and a.count(i) == 0)
            b.push_back(i);
        }
      }
      if (b.empty())
        break;
      for (int x : b)
        a.insert(x);
    }
    return a.size();
  }
};
