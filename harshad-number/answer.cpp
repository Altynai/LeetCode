class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    string s = to_string(x);
    int sum = 0;
    for (char ch : s)
      sum += ch - '0';
    return x % sum == 0 ? sum : -1;
  }
};
