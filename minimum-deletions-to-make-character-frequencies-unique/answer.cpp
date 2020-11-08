class Solution {
public:
  int minDeletions(string s) {
    int n = 26;
    vector<int> feq(n, 0);
    for (char c : s)
      feq[c - 'a'] += 1;

    sort(feq.begin(), feq.end(), greater<int>());
    unordered_set<int> seen(feq.begin(), feq.end());

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (feq[i] == feq[i + 1]) {
        int val = feq[i];
        while (val > 0 && seen.count(val))
          val--;
        ans += feq[i] - val;
        seen.insert(val);
      }
    }
    return ans;
  }
};
