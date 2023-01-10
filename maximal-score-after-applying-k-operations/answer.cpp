class Solution {
public:
  long long maxKelements(vector<int> &a, int k) {
    priority_queue<int> q;
    for (int x : a)
      q.push(x);

    long long ans = 0;
    while (k > 0 and !q.empty()) {
      int x = q.top();
      q.pop();

      ans += x;
      k--;

      x = (x + 2) / 3;
      if (x > 0)
        q.push(x);
    }
    return ans;
  }
};
