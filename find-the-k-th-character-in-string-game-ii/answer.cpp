const int N = 26;

using int64 = long long;

class Solution {
public:
  char kthCharacter(long long k, vector<int> &operations) {
    // find 2^p >= k
    int64 p = 1;
    while (p * 2 < k)
      p *= 2;
    p *= 2;

    vector<pair<int64, int64>> path;
    int64 nxt = k;
    for (int64 x = p; x > 1; x /= 2) {
      int64 half = x / 2;
      if (k <= half)
        path.push_back({k, nxt});
      else {
        path.push_back({k - half, nxt});
        k -= half;
        nxt = k;
      }
    }
    reverse(path.begin(), path.end());

    int now = 0, n = operations.size();
    p = 1;
    // later operation won't change k anymore
    for (int i = 0; i < min((int)path.size(), n); i++) {
      if (operations[i] == 1) {
        auto [x, y] = path[i];
        if (x <= p and y > p)
          now = (now + 1) % N;
      }
      p *= 2;
    }
    return 'a' + now;
  }
};
