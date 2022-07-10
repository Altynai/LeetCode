class Solution {
public:
  int fillCups(vector<int> &a) {
    int ans = 0;
    sort(a.begin(), a.end());
    while (a[2] > 0) {
      if (a[1] > 0 and a[2] > 0)
        ans++, a[1]--, a[2]--;
      else
        ans++, a[2]--;
      sort(a.begin(), a.end());
    }
    return ans;
  }
};
