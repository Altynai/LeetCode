class Solution {
public:
  int minOperations(vector<string> &logs) {
    int m = 0;
    for (string &log : logs) {
      if (log == "./")
        continue;
      else if (log == "../") {
        if (m)
          m -= 1;
      } else {
        m++;
      }
    }
    return m;
  }
};
