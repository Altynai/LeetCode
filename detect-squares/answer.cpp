class DetectSquares {
private:
  map<pair<int, int>, int> cnt;

  int cal(pair<int, int> p) {
    auto it = cnt.find(p);
    return (it == cnt.end() ? 0 : it->second);
  }

public:
  DetectSquares() { cnt.clear(); }

  void add(vector<int> point) { cnt[{point[0], point[1]}] += 1; }

  int count(vector<int> point) {
    int ans = 0;
    for (auto [p, c] : cnt) {
      if (p.first == point[0] || p.second == point[1] ||
          abs(p.first - point[0]) != abs(p.second - point[1]))
        continue;
      ans += c * cal({p.first, point[1]}) * cal({point[0], p.second});
    }
    return ans;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
