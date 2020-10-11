template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  os << "]";
  return os;
}

template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "]";
}

template <typename T> inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "}";
}

template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "}";
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "]";
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
  cout << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

// types
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define si set<int>
#define mpii map<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>

// names
#define pb push_back
#define fi first
#define se second
#define mp(a, b) make_pair((a), (b))
#define sz(a) ((int)(a).size())
#define rep(i, s, t) for (int i = (s); i < (t); i++)
#define repn(i, s) for (int i = 0; i < (s); i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

// constants
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

// =====================================================================================================================
#define maxn 100006

class Solution {

public:
  bool checkPalindromeFormation(string a, string b) {
    int n = sz(a);
    if (n == 1)
      return 1;

    auto generate = [&](const string &x) {
      vb p(n + 1, 0);
      p[0] = 1;

      int r = n / 2;
      int l = (n & 1) ? r : r - 1;

      if (x[l] == x[r])
        p[r - l + 1] = 1;

      l--, r++;

      while (l >= 0 && r <= n - 1 && x[l] == x[r]) {
        if (p[r - l - 1])
          p[r - l + 1] = 1;
        else
          break;
        l--, r++;
      }
      return p;
    };

    auto check = [&](const string &x, const string &y) {
      vb px = generate(x);
      vb py = generate(y);

      repn(i, n / 2) {
        if (x[i] != y[n - 1 - i])
          break;
        if (px[n - (i + 1) * 2] || py[n - (i + 1) * 2])
          return 1;
      }
      return 0;
    };

    return check(a, b) || check(b, a);
  }
};
