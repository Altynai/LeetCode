class Solution {
public:
  int minimumArrayLength(vector<int> &a) {
    sort(a.begin(), a.end());
    // we can use num[i] < num[j] to remove num[j]

    // another way to remove one minimal value:
    // num[0] * num[i] = num[k] (num[0] < num[i] < num[k])
    // we can use num[k] % num[0] to get another num[i]
    int cnt = count(a.begin(), a.end(), a[0]);
    int ans = (cnt + 1) / 2;

    // or we can just find a better minimal value?
    for (int i = cnt; i < a.size(); i++) {
      int mod = a[i] % a[0];
      if (0 < mod and mod < a[0])
        ans = min(ans, 1);
    }
    return ans;
  }
};
