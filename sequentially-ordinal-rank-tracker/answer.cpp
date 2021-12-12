class SORTracker {
private:
  set<pair<int, string>> top, other;
  int n;

public:
  SORTracker() {
    top.clear(), other.clear();
    n = 1;
  }

  void add(string name, int score) { other.emplace(-score, name); }

  string get() {
    while (top.size() < n && other.size()) {
      auto it = other.begin();
      top.insert(*it);
      other.erase(it);
    }
    // swap
    while (other.size() && (*other.begin()) < (*prev(top.end()))) {
      auto a = *prev(top.end());
      top.erase(prev(top.end()));
      auto b = *other.begin();
      other.erase(b);

      top.insert(b);
      other.insert(a);
    }
    n += 1;
    return prev(top.end())->second;
  }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
