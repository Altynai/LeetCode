class Solution {
public:
  int minMaxDifference(int num) {
    string s = to_string(num);
    int k = -1;
    for (char &ch : s) {
      if (k == -1 and ch != '9')
        k = ch - '0';
      if (ch - '0' == k)
        ch = '9';
    }

    string t = to_string(num);
    k = -1;
    for (char &ch : t) {
      if (k == -1 and ch != '0')
        k = ch - '0';
      if (ch - '0' == k)
        ch = '0';
    }

    return stoi(s) - stoi(t);
  }
};
