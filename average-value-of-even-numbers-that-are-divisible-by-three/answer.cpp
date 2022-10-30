class Solution {
public:
  int averageValue(vector<int> &a) {
    int sum = 0, cnt = 0;
    for (int x : a) {
      if (x % 3 == 0 and x % 2 == 0)
        sum += x, cnt++;
    }
    return cnt ? sum / cnt : 0;
  }
};
