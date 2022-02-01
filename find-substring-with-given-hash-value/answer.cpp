class Solution {
public:
  string subStrHash(string s, int power, int mod, int k, int hashValue) {
    auto add = [&](int a, int b) -> int { return (a + b) % mod; };

    auto sub = [&](int a, int b) -> int { return add(a, mod - b); };

    auto mul = [&](int a, int b) -> int { return 1LL * a * b % mod; };

    auto pow = [&](int x, int m) -> int {
      assert(m >= 0);
      int res = 1, p = x;
      while (m) {
        if (m & 1)
          res = mul(res, p);
        p = mul(p, p);
        m /= 2;
      }
      return res;
    };

    int n = s.size();
    int pk = 1, hval = 0, pos = -1;
    for (int i = n - k; i < n; i++) {
      int val = s[i] - 'a' + 1;
      hval = add(hval, mul(val, pk));
      pk = mul(pk, power);
    }
    if (hval == hashValue)
      pos = n - k;

    pk = pow(power, k - 1);
    for (int i = n - k - 1; i >= 0; i--) {
      int val = s[i + k] - 'a' + 1;
      hval = sub(hval, mul(val, pk));
      hval = mul(hval, power);

      val = s[i] - 'a' + 1;
      hval = add(hval, val);

      if (hval == hashValue)
        pos = i;
    }
    assert(pos != -1);
    return s.substr(pos, k);
  }
};
