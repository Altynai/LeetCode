class Solution {
public:
  long long continuousSubarrays(vector<int> &a) {
    int n = a.size();
    multiset<int> s;

    auto good = [&](int x) -> bool {
      if (s.empty())
        return 1;
      int min = *s.begin(), max = *prev(s.end());
      if (x <= min)
        return max - x <= 2;
      else if (x >= max)
        return x - min <= 2;
      return 1;
    };

    long long ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < n and good(a[j]))
        s.insert(a[j++]);
      ans += j - i;
      s.erase(s.find(a[i]));
    }
    return ans;
  }
};
