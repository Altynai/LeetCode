class Solution {
public:
  int countCompleteSubarrays(vector<int> &a) {
    int k = set<int>(a.begin(), a.end()).size();
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      set<int> s;
      for (int j = i; s.size() <= k and j < n; j++) {
        s.insert(a[j]);
        if (s.size() == k)
          ans++;
      }
    }
    return ans;
  }
};
