class Solution {
public:
  int halveArray(vector<int> &a) {
    priority_queue<double> q;
    double sum = 0;
    for (int x : a) {
      q.push(x);
      sum += x;
    }

    double half = sum / 2;
    int ans = 0;
    while (sum > half) {
      double x = q.top();
      q.pop();
      ans++;
      sum -= x / 2;
      q.push(x / 2);
    }
    return ans;
  }
};
