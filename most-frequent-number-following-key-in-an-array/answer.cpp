class Solution {
public:
  int mostFrequent(vector<int> &a, int key) {
    int n = a.size();
    map<int, int> c;
    for (int i = 1; i < n; i++)
      if (a[i - 1] == key)
        c[a[i]]++;

    int target = -1, cnt = 0;
    for (auto [k, v] : c) {
      if (v > cnt)
        target = k, cnt = v;
    }
    return target;
  }
};
