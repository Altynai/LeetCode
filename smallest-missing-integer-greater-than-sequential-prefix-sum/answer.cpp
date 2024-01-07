class Solution {
public:
  int missingInteger(vector<int> &a) {
    unordered_set<int> s(a.begin(), a.end());

    int n = a.size(), sum = a[0];
    for (int i = 1; i < n and a[i] == a[i - 1] + 1; i++)
      sum += a[i];

    while (s.count(sum))
      sum++;
    return sum;
  }
};
