class Solution {
public:
  bool canAliceWin(vector<int> &a) {
    int n = a.size(), sum = accumulate(a.begin(), a.end(), 0);
    int single = 0;
    for (int x : a) {
      if (x < 10)
        single += x;
    }
    return single > sum - single or sum - single > single;
  }
};
