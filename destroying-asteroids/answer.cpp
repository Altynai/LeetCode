class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();

    long long m = mass;
    for (int i = 0; i < n; i++) {
      if (m < a[i])
        return 0;
      m += a[i];
    }
    return 1;
  }
};
