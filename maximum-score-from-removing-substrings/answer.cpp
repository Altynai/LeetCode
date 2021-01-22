class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int n = 0;
    vector<char> v;

    char a = 'a', b = 'b';
    if (y > x)
      swap(a, b), swap(x, y);

    int ans = 0;
    for (char ch : s) {
      v.push_back(ch);
      n++;
      while (n >= 2 && v[n - 2] == a && v[n - 1] == b) {
        ans += x;
        v.pop_back();
        v.pop_back();
        n -= 2;
      }
    }

    vector<char> v2 = v;
    n = 0;
    v.clear();
    for (char ch : v2) {
      v.push_back(ch);
      n++;
      while (n >= 2 && v[n - 2] == b && v[n - 1] == a) {
        ans += y;
        v.pop_back();
        v.pop_back();
        n -= 2;
      }
    }
    return ans;
  }
};
