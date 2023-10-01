using int64 = long long;

struct Node {
  int idx;
  int height;
  int64 sum;

  Node(){};
  Node(int idx, int height, int64 sum) : idx(idx), height(height), sum(sum) {}
};

class Solution {
private:
  vector<Node> calculate(const vector<int> &maxHeights) {
    int n = maxHeights.size();
    const Node &node = {0, maxHeights[0], maxHeights[0]};
    vector<Node> stack = {node};
    vector<Node> ans = {node};

    for (int i = 1; i < n; i++) {
      int h = maxHeights[i];
      while (!stack.empty() and stack.back().height > h)
        stack.pop_back();

      if (stack.empty())
        stack.push_back({i, h, 1LL * h * (i + 1)});
      else {
        const Node &prev = stack.back();
        assert(prev.height <= h);
        stack.push_back({i, h, prev.sum + 1LL * h * (i - prev.idx)});
      }

      ans.push_back(stack.back());
    }
    return ans;
  }

public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();

    vector<Node> f = calculate(maxHeights);
    reverse(maxHeights.begin(), maxHeights.end());
    vector<Node> g = calculate(maxHeights);

    int64 ans = max(f[n - 1].sum, g[n - 1].sum);
    for (int i = 1; i < n; i++)
      ans = max(ans, f[i - 1].sum + g[n - 1 - i].sum);
    return ans;
  }
};
