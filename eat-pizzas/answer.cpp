using int64 = long long;

class Solution {
public:
  long long maxWeight(vector<int> &p) {
    int n = p.size();
    sort(p.begin(), p.end());

    int days = n / 4;
    int odd = (days + 1) / 2;
    int even = days - odd;

    int64 ans = 0;
    for (int i = 1; i <= odd; i++)
      ans += p[n - i];
    for (int i = 1, j = n - odd - 2; i <= even; i++, j -= 2)
      ans += p[j];
    return ans;
  }
};
