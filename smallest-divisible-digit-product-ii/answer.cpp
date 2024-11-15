template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

const vector<int> Primes = {2, 3, 5, 7};

class Solution {
private:
  void modify(vector<int> &freq, int x, int sign) {
    if (x == 0)
      return;
    for (int p : Primes) {
      while (x % p == 0)
        x /= p, freq[p] += sign;
    }
  }

  int minimalLength(vector<int> freq) {
    // ignore negatives
    for (int &x : freq)
      x = max(x, 0);

    int len = 0;
    len += freq[3] / 2, freq[3] -= freq[3] / 2 * 2;
    len += freq[2] / 3, freq[2] -= freq[2] / 3 * 3;
    len += freq[7];
    if (freq[3] % 2 == 1 and freq[2] > 0)
      len++, freq[3]--, freq[2]--;
    len += freq[5];
    if (freq[2] % 3 == 2)
      len++, freq[2] -= 2;
    if (freq[3] % 2 == 1)
      len++, freq[3]--;
    if (freq[2] % 2 == 1)
      len++, freq[2]--;
    return len;
  };

  bool canChoose(const vector<int> &freq, int digit) {
    if (digit == 9)
      return freq[3] >= 2;
    if (digit == 8)
      return freq[2] >= 3;
    if (digit == 7)
      return freq[7] >= 1;
    if (digit == 6)
      return freq[3] >= 1 and freq[2] >= 1;
    if (digit == 5)
      return freq[5] >= 1;
    if (digit == 4)
      return freq[2] >= 2;
    if (digit == 3)
      return freq[3] >= 1;
    if (digit == 2)
      return freq[2] >= 1;
    return true;
  }

  // always put larger digits at the end first
  string generate(vector<int> freq) {
    for (int &x : freq)
      x = max(x, 0);

    string ans;
    ans += string(freq[3] / 2, '9'), freq[3] -= freq[3] / 2 * 2;
    ans += string(freq[2] / 3, '8'), freq[2] -= freq[2] / 3 * 3;
    ans += string(freq[7], '7');
    if (freq[3] % 2 == 1 and freq[2] > 0)
      ans.push_back('6'), freq[3]--, freq[2]--;
    ans += string(freq[5], '5');
    if (freq[2] % 3 == 2)
      ans.push_back('4'), freq[2] -= 2;
    if (freq[3] % 2 == 1)
      ans.push_back('3'), freq[3]--;
    if (freq[2] % 2 == 1)
      ans.push_back('2'), freq[2]--;
    reverse(ans.begin(), ans.end());
    return ans;
  }

public:
  string smallestNumber(string s, long long t) {
    int64 x = t;
    vector<int> need(10, 0);
    for (int p : Primes) {
      while (x % p == 0)
        x /= p, need[p]++;
    }
    if (x > 1)
      return "-1";

    int n = s.size();
    int zero = s.find('0');
    if (zero != -1) {
      for (int i = zero; i < n; i++)
        s[i] = '1';
    }

    // case 1: s itself is good
    int64 mod = 1;
    for (char ch : s) {
      mod = mod * (ch - '0') % t;
    }
    if (mod == 0)
      return s;

    // case 2: answer has length = n
    // so some suffix should be changed, and we should find the shortest one
    // as 10^14 < 2^64, this suffix should be less than 64
    vector<int> had(10, 0);
    for (char ch : s)
      modify(had, ch - '0', +1);

    for (int i = n - 1; i >= 0; i--) {
      modify(had, s[i] - '0', -1);

      vector<int> left(10, 0);
      for (int j = 0; j < 10; j++)
        umax(left[j], need[j] - had[j]);

      int found = -1;
      for (int digit = s[i] - '0' + 1; digit <= 9; digit++) {
        modify(left, digit, -1);
        int m = minimalLength(left);
        modify(left, digit, +1);
        if (i + 1 + m <= n) {
          found = digit;
          break;
        }
      }
      if (found != -1) {
        modify(left, found, -1);
        s[i] = '0' + found;
        string sfx = generate(left);
        int m = sfx.size();
        return s.substr(0, i + 1) + string(n - m - (i + 1), '1') + sfx;
      }
    }

    // case 3: answer has length n + 1
    string ans = generate(need);
    int m = ans.size();
    if (m <= n)
      ans = string(n + 1 - m, '1') + ans;
    return ans;
  }
};
