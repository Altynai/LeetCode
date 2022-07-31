class Solution {
public:
  int maximumGroups(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int cnt = 1, ans = 1, sum = a[0];
    for (int i = 1; i < n;) {
      int j = i, total = 0, num = 0;
      while (j < n and (total <= sum or num <= cnt)) {
        total += a[j];
        num++;
        j++;
      }
      if (total > sum and num > cnt) {
        ans++;
        sum = total;
        cnt = num;
      } else {
        break;
      }

      i = j;
    }
    return ans;
  }
};
