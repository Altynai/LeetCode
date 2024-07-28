class Solution {
private:
  struct Point {
    double x, y;
  };

  struct Circle {
    Point center;
    double radius;
  };

  struct Segment {
    Point start, end;
  };

  double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
  }

  double pointToSegmentDistance(const Point &p, const Segment &seg) {
    double l2 =
        pow(seg.end.x - seg.start.x, 2) + pow(seg.end.y - seg.start.y, 2);
    if (l2 == 0)
      return distance(p, seg.start);

    double t = ((p.x - seg.start.x) * (seg.end.x - seg.start.x) +
                (p.y - seg.start.y) * (seg.end.y - seg.start.y)) /
               l2;
    t = std::max(0.0, std::min(1.0, t));

    Point projection = {seg.start.x + t * (seg.end.x - seg.start.x),
                        seg.start.y + t * (seg.end.y - seg.start.y)};

    return distance(p, projection);
  }

  bool isCircleIntersectSegment(const Circle &circle, const Segment &segment) {
    if (distance(circle.center, segment.start) <= circle.radius ||
        distance(circle.center, segment.end) <= circle.radius) {
      return true;
    }
    double dist = pointToSegmentDistance(circle.center, segment);
    return dist <= circle.radius;
  }

public:
  bool canReachCorner(int X, int Y, vector<vector<int>> &circles) {
    // model 4 edges as points, build a graph together with circles
    // if left and down/right are connected, then false
    // if up and down/right are connected, then false

    int n = circles.size();
    int up = n, right = n + 1, down = n + 2, left = n + 3;
    int m = n + 4;
    vector<vector<int>> adj(m);

    auto AddEdge = [&](int u, int v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    };

    for (int i = 0; i < n; i++) {
      double x0 = circles[i][0], y0 = circles[i][1], r0 = circles[i][2];
      Circle c = {{x0, y0}, r0};

      // connected with 4 edges
      if (isCircleIntersectSegment(c, {{0, Y * 1.0}, {X * 1.0, Y * 1.0}}))
        AddEdge(i, up);
      if (isCircleIntersectSegment(c, {{X * 1.0, 0}, {X * 1.0, Y * 1.0}}))
        AddEdge(i, right);
      if (isCircleIntersectSegment(c, {{0, 0}, {X * 1.0, 0}}))
        AddEdge(i, down);
      if (isCircleIntersectSegment(c, {{0, 0}, {0, Y * 1.0}}))
        AddEdge(i, left);

      // connected with other circles
      for (int j = i + 1; j < n; j++) {
        double x1 = circles[j][0], y1 = circles[j][1], r1 = circles[j][2];
        double dx = x0 - x1, dy = y0 - y1;
        if (dx * dx + dy * dy <= (r0 + r1) * (r0 + r1))
          AddEdge(i, j);
      }
    }

    vector<pair<int, int>> candidates = {
        {left, down}, {right, up}, {left, right}, {down, up}};
    for (auto [start, end] : candidates) {
      vector<bool> vis(m, 0);
      queue<int> que;
      que.push(start);
      vis[start] = 1;
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : adj[u]) {
          if (vis[v])
            continue;
          if (v == end)
            return false;
          que.push(v);
          vis[v] = 1;
        }
      }
    }

    return true;
  }
};
