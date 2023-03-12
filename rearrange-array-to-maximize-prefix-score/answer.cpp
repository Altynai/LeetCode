using int64 = long long;

class Solution {
public:
  int maxScore(vector<int> &a) {
    vector<int> neg;
    int ans = 0;
    int64 sum = 0;

    for (int x : a) {
      if (x >= 0)
        sum += x, ans++;
      else
        neg.push_back(x);
    }
    if (sum == 0)
      ans = 0;

    if (sum > 0) {
      sort(neg.begin(), neg.end());
      reverse(neg.begin(), neg.end());
      for (int x : neg) {
        sum += x;
        if (sum > 0)
          ans++;
      }
    }
    return ans;
  }
};
