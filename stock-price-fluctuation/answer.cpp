class StockPrice {
private:
  multiset<int> p;
  map<int, int> tp;

public:
  StockPrice() {
    p.clear();
    tp.clear();
  }

  void update(int timestamp, int price) {
    auto it = tp.find(timestamp);
    if (it != tp.end()) {
      p.erase(p.find(it->second));
    }
    tp[timestamp] = price;
    p.insert(price);
  }

  int current() { return prev(tp.end())->second; }

  int maximum() { return *prev(p.end()); }

  int minimum() { return *p.begin(); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
