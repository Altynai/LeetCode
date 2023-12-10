using int64 = long long;

class Solution {
public:
  long long countSubarrays(vector<int> &a, int k) {
    int val = *max_element(a.begin(), a.end());
    int n = a.size();

    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (a[i] == val)
        pos.push_back(i);
    }

    int m = pos.size();
    if (m < k)
      return 0;

    int64 ans = 0;
    int last = -1;
    for (int i = 0; i + k - 1 < m; i++) {
      int j = i + k - 1;
      ans += 1LL * (pos[i] - last) * (n - pos[j]);
      last = pos[i];
    }
    return ans;
  }
};
