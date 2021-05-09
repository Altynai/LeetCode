struct Set {
  multiset<int> m;
  long long sum;
  Set() {
    sum = 0;
    m.clear();
  }

  inline int size() { return m.size(); }

  inline bool contains(int val) { return m.find(val) != m.end(); }

  void remove(int val) {
    // assert(contains(val));
    auto it = m.find(val);
    m.erase(it);
    sum -= val;
  }

  void add(int val) {
    m.insert(val);
    sum += val;
  }
};

class MKAverage {

  int cnt;
  int k;
  int m;
  Set a, b, c;
  deque<int> q;

  void remove(int val) {
    if (c.contains(val))
      c.remove(val);
    else if (b.contains(val))
      b.remove(val);
    else
      a.remove(val);
  }

  void add(int val) {
    if (c.size() && val >= *c.m.begin())
      c.add(val);
    else if (a.size() && val <= *prev(a.m.end()))
      a.add(val);
    else
      b.add(val);
  }

  void balance() {
    while (a.size() > k) {
      int val = *prev(a.m.end());
      a.remove(val);
      b.add(val);
    }
    while (b.size() > m - k * 2) {
      int val = *prev(b.m.end());
      b.remove(val);
      c.add(val);
    }

    while (c.size() > k) {
      int val = *c.m.begin();
      c.remove(val);
      b.add(val);
    }
    while (b.size() > m - k * 2) {
      int val = *b.m.begin();
      b.remove(val);
      a.add(val);
    }
  }

public:
  MKAverage(int _m, int _k) {
    cnt = 0;
    m = _m;
    k = _k;
    a = Set();
    b = Set();
    c = Set();
    q.clear();
  }

  void addElement(int num) {
    if (q.size() == m) {
      int val = q.front();
      q.pop_front();
      remove(val);
    }
    cnt++;
    q.push_back(num);
    add(num);
    balance();
  }

  int calculateMKAverage() {
    if (cnt < m)
      return -1;
    return b.sum / b.size();
  }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
