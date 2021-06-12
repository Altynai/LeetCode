// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
// =====================================================================================================================

using State = array<int, 2>;

const State AND = {-1, -1};
const State OR = {-2, -2};
const State RP = {-3, -3};

class Solution {
private:
  inline int eval(int a, char op, int b) {
    return op == '&' ? (a & b) : (a | b);
  }

  int cal(const string &exp) {
    vector<char> s(exp.size());
    int n = 0;
    for (char ch : exp) {
      if (ch == '(') {
        int a = s[--n] - '0';
        while (s[n - 1] != ')') {
          char op = s[--n];
          int b = s[--n] - '0';
          a = eval(a, op, b);
        }
        s[--n]; // pop ')'
        s[n++] = '0' + a;
      } else {
        s[n++] = ch;
      }
    }
    while (n >= 3) {
      int a = s[--n] - '0';
      char op = s[--n];
      int b = s[--n] - '0';
      a = eval(a, op, b);
      s[n++] = '0' + a;
    }
    return s[0] - '0';
  }

  State transfer(const State &a, const State &op, const State &b) {
    State best = {INT_MAX, INT_MAX};
    for (int j = 0; j < 2; j++) {
      for (char ch : "&|") {
        for (int k = 0; k < 2; k++) {
          int cnt = (ch == '&' ? (op != AND) : (op != OR));
          int res = (ch == '&' ? (j & k) : (j | k));
          umin(best[res], a[j] + b[k] + cnt);
        }
      }
    }
    return best;
  }

public:
  int minOperationsToFlip(string exp) {
    reverse(exp.begin(), exp.end());
    int ans = cal(exp), n = exp.size();

    vector<State> s(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
      if (exp[i] == '(') {
        State a = s[--m];
        while (s[m - 1] != RP) {
          State op = s[--m];
          State b = s[--m];
          a = transfer(a, op, b);
        }
        s[--m]; // pop ')'
        s[m++] = a;
      } else if (exp[i] == '0') {
        s[m++] = {0, 1};
      } else if (exp[i] == '1') {
        s[m++] = {1, 0};
      } else if (exp[i] == '&') {
        s[m++] = AND;
      } else if (exp[i] == '|') {
        s[m++] = OR;
      } else {
        s[m++] = RP;
      }
    }

    while (m >= 3) {
      State a = s[--m];
      State op = s[--m];
      State b = s[--m];
      s[m++] = transfer(a, op, b);
    }
    return s[0][ans ^ 1];
  }
};
