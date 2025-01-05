template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

using int64 = long long;

template <class Info> struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN];
  Info nodes[MAXN];

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = Info();
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void build(int p, int l, int r, const vector<Info> &v) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = v[l];
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, v);
      build(rson(p), mid + 1, r, v);
      pull(p);
    }
  }

  void pull(int p) { nodes[p] = nodes[lson(p)] + nodes[rson(p)]; }

  void update(int p, int pos, const Info &val) {
    if (L[p] == R[p]) {
      nodes[p] = nodes[p] + val;
      return;
    }
    int mid = (L[p] + R[p]) >> 1;
    if (pos <= mid)
      update(lson(p), pos, val);
    else
      update(rson(p), pos, val);
    pull(p);
  }

  Info query(int p, int l, int r) {
    if (L[p] == l && R[p] == r)
      return nodes[p];

    int mid = (L[p] + R[p]) >> 1;
    if (r <= mid)
      return query(lson(p), l, r);
    else if (l > mid)
      return query(rson(p), l, r);
    else {
      return query(lson(p), l, mid) + query(rson(p), mid + 1, r);
    }
  }
};

// NOT the best, but works
unordered_map<int, int> IDS;

struct State {
  int64 score;
  int prev_id;
  int curr_id;

  State() : score(0), prev_id(-1), curr_id(-1) {}
  State(int64 s, int pid, int cid) : score(s), prev_id(pid), curr_id(cid) {}

  bool empty() const { return score == 0; }

  friend State operator+(const State &a, const State &b) {
    if (a.score != b.score)
      return a.score > b.score ? a : b;
    else if (IDS[a.prev_id] != IDS[b.prev_id])
      return IDS[a.prev_id] < IDS[b.prev_id] ? a : b;
    return IDS[a.curr_id] < IDS[b.curr_id] ? a : b;
  }
};
SegmentTree<State> st[4];

class Solution {
public:
  vector<int> maximumWeight(vector<vector<int>> &intervals) {
    // sort ranges by right endpoint
    // dp[i] = max(dp[j]) + weight_i if range j not overlapping with range i
    // this can be done with segment tree or binary index tree

    // how to save the state? state is {weight, previous range id}
    // looks like we can just use 4 segment trees to help dp transition

    vector<int> v;
    for (auto i : intervals) {
      v.push_back(i[0]);
      v.push_back(i[1]);
    }
    int m = deduplicate(v);

    int n = intervals.size();
    // [l, r, weight, id]
    vector<array<int, 4>> ranges(n);
    for (int i = 0; i < n; i++) {
      int l = lower_bound(v.begin(), v.end(), intervals[i][0]) - v.begin();
      int r = lower_bound(v.begin(), v.end(), intervals[i][1]) - v.begin();
      ranges[i] = {l, r, intervals[i][2], i};
    }
    sort(ranges.begin(), ranges.end(),
         [](const auto &lhs, const auto &rhs) { return lhs[1] < rhs[1]; });

    vector<vector<State>> dp(4, vector<State>(n, State()));
    for (int i = 0; i < 4; i++)
      st[i].build(1, 0, m - 1);

    // if we only choose one range
    IDS.clear();
    for (int i = 0; i < n; i++)
      IDS[i] = ranges[i][3];
    for (int i = 0; i < n; i++) {
      auto [l, r, weight, id] = ranges[i];
      st[0].update(1, r, {weight, -1, i});
      dp[0][i] = st[0].query(1, 0, r);
    }

    for (int chosen = 2; chosen <= 4; chosen++) {
      SegmentTree<State> &prev_tree = st[chosen - 2];
      SegmentTree<State> &curr_tree = st[chosen - 1];

      for (int i = 0; i < n; i++) {
        auto [l, r, weight, id] = ranges[i];
        if (l > 0) {
          State res = prev_tree.query(1, 0, l - 1);
          if (res.empty())
            continue;
          State upd = State(res.score + weight, res.curr_id, i);
          dp[chosen - 1][i] = dp[chosen - 1][i] + upd;
          curr_tree.update(1, r, dp[chosen - 1][i]);
        }
      }
    }

    auto FindSeq = [&](int depth, State state) -> vector<int> {
      vector<int> seq(1, IDS[state.curr_id]);
      for (int i = depth - 1; i >= 0; i--) {
        State res = dp[i][state.prev_id];
        seq.push_back(IDS[res.curr_id]);
        state = res;
      }
      sort(seq.begin(), seq.end());
      return seq;
    };

    int best = 0;
    vector<int> ans;
    for (int i = 0; i <= 3; i++) {
      State res = st[i].query(1, 0, m - 1);
      if (res.empty())
        continue;
      vector<int> seq = FindSeq(i, res);
      if (res.score > best)
        ans = seq, best = res.score;
      else if (res.score == best and seq < ans)
        ans = seq;
    }
    return ans;
  }
};
