class Solution {
public:
  int maxOperations(vector<int> &a) {
    int ans = 1, sum = a[0] + a[1], n = a.size();
    for (int i = 2; i + 1 < n; i += 2) {
      if (a[i] + a[i + 1] == sum)
        ans++;
      else
        break;
    }
    return ans;
  }
};
