class Solution {
public:
  vector<int> bestCoordinate(vector<vector<int>> &towers, int radius) {
    int best = -1, x = -1, y = -1;
    double r = radius;
    for (int i = 0; i <= 50; i++) {
      for (int j = 0; j <= 50; j++) {
        int signal = 0;
        for (auto &t : towers) {
          double dx = abs(t[0] - i);
          double dy = abs(t[1] - j);
          double d = sqrt(dx * dx + dy * dy);
          if (d > r)
            continue;
          signal += (int)((1.0 * t[2]) / (d + 1));
        }
        if (signal > best) {
          best = signal;
          x = i;
          y = j;
        }
      }
    }
    return {x, y};
  }
};
