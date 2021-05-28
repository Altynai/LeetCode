// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  bool checkZeroOnes(string s) {
    int cur = 1, n = s.size();
    vector<int> len(2, 0);
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        cur++;
      else {
        umax(len[s[i - 1] - '0'], cur);
        cur = 1;
      }
    }
    if (cur)
      umax(len[s[n - 1] - '0'], cur);
    return len[1] > len[0];
  }
};
