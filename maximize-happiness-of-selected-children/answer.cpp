using int64 = long long;

class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    int64 ans = 0;

    sort(happiness.rbegin(), happiness.rend());
    int n = happiness.size();
    for (int i = 0; i < k; i++) {
      int val = happiness[i] - i;
      ans += max(val, 0);
    }
    return ans;
  }
};
