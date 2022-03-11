class MyCalendarThree {
private:
  map<int, int> p;

public:
  MyCalendarThree() { p.clear(); }

  int book(int start, int end) {
    p[start] += 1;
    p[end] -= 1;

    int ans = 0, cur = 0;
    for (auto [when, cnt] : p) {
      cur += cnt;
      ans = max(cur, ans);
    }
    return ans;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
