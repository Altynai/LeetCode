const int N = 26;

class Solution {
public:
  char kthCharacter(int k) {
    // find 2^p >= k
    int p = 1;
    while (p * 2 < k)
      p *= 2;
    p *= 2;

    vector<pair<int, int>> path;
    int nxt = k;
    for (int x = p; x > 1; x /= 2) {
      int half = x / 2;
      if (k <= half)
        path.push_back({k, nxt});
      else {
        path.push_back({k - half, nxt});
        k -= half;
        nxt = k;
      }
    }
    reverse(path.begin(), path.end());

    int now = 0;
    p = 1;
    for (int i = 0; i < path.size(); i++) {
      auto [x, y] = path[i];
      if (x <= p and y > p)
        now = (now + 1) % N;
      p *= 2;
    }
    return 'a' + now;
  }
};
