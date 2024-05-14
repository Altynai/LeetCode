#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

using int64 = long long;

const int N = 51;

class Solution {

  // count number of integers [1 ... n] where p-th bit is set
  // 如果用数位 dp 写会卡常数，出题人请问你这样很有意思吗？
  int64 count(int64 n, int p) {
    // 出现情况以 2 ^ (p + 1) 为周期，因为
    // 一开始当 p = 0: 考虑后面的低位，一共有 2 ^ p 个数
    // 然后当 p = 1: 考虑后面的低位，一共也有 2 ^ p 个数

    int64 len = 1LL << p, len2 = len * 2;
    // 先计算完整周期的数量
    int64 ret = n / len2;
    ret *= len;
    // 再计算最后一个不完整周期的出现次数
    int64 rem = n % len2;
    if (rem >= len)
      ret += rem - len + 1;
    return ret;
  }

  // find the first number n satisfies the length of powerful arrays made of [1
  // ... n] is >= pos
  int64 firstNumber(int64 pos) {
    int64 ans = -1;
    for (int64 l = 1, r = pos; l <= r;) {
      int64 mid = (l + r) / 2;
      int64 cnt = 0;
      for (int i = 0; i < N; i++)
        cnt += count(mid, i);
      if (cnt >= pos)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    assert(ans != -1);
    return ans;
  }

  // length of powerful array for [1 ... n]
  int64 powerfulArrayLength(int64 n) {
    int64 len = 0;
    for (int i = 0; i < N; i++)
      len += count(n, i);
    return len;
  }

  // sum of powerful array made from [1 ... n]
  int64 powerfulArraySum(int64 n) {
    int64 sum = 0;
    for (int i = 0; i < N; i++)
      sum += count(n, i) * i;
    return sum;
  }

  int query(int64 l, int64 r, int mod) {
    int64 left = firstNumber(l), right = firstNumber(r);
    int64 sum = powerfulArraySum(right) - powerfulArraySum(left - 1);

    // handle the endpoints
    int64 pos = powerfulArrayLength(left - 1) + 1;
    for (int i = 0; i < N and pos < l; i++) {
      if (bit(left, i)) {
        sum -= i;
        pos++;
      }
    }
    assert(pos == l);

    pos = powerfulArrayLength(right - 1) + 1;
    bool trim = 0;
    for (int i = 0; i < N; i++) {
      if (bit(right, i)) {
        if (pos > r)
          trim = 1;
        if (trim)
          sum -= i;
        pos++;
      }
    }

    int64 res = 1, p = 2;
    while (sum > 0) {
      if (sum & 1)
        res = res * p % mod;
      p = p * p % mod;
      sum /= 2;
    }
    return res % mod;
  }

public:
  vector<int> findProductsOfElements(vector<vector<long long>> &queries) {
    // https://oeis.org/A133457

    int n = queries.size();
    vector<int> ans;
    for (auto q : queries)
      ans.push_back(query(q[0] + 1, q[1] + 1, q[2]));
    return ans;
  }
};
