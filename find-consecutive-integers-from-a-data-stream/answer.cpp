class DataStream {
  int value, k, cnt;
  queue<int> q;

public:
  DataStream(int value, int k) {
    this->value = value;
    this->k = k;
    cnt = 0;
    q = queue<int>();
  }

  bool consec(int x) {
    q.push(x);
    if (x == value)
      cnt++;

    while (q.size() > k) {
      int y = q.front();
      q.pop();
      if (y == value)
        cnt--;
    }
    return cnt == k;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
