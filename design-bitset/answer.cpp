class Bitset {
private:
  vector<unordered_set<int>> sets;
  int n, default_val;

public:
  Bitset(int size) {
    sets = vector<unordered_set<int>>(2, unordered_set<int>());
    n = size;
    default_val = 0;
  }

  void fix(int idx) {
    if (sets[0].count(idx))
      sets[0].erase(idx);
    sets[1].insert(idx);
  }

  void unfix(int idx) {
    if (sets[1].count(idx))
      sets[1].erase(idx);
    sets[0].insert(idx);
  }

  void flip() {
    swap(sets[0], sets[1]);
    default_val ^= 1;
  }

  bool all() {
    if (default_val == 1)
      return sets[0].size() == 0;
    else
      return sets[1].size() == n;
  }

  bool one() {
    if (default_val == 1)
      return sets[0].size() < n;
    else
      return sets[1].size() > 0;
  }

  int count() {
    if (default_val == 1)
      return n - sets[0].size();
    else
      return sets[1].size();
  }

  string toString() {
    string s(n, '0');
    for (int i = 0; i < n; i++) {
      if (sets[0].count(i))
        continue;
      if (default_val == 1 or sets[1].count(i))
        s[i] = '1';
    }
    return s;
  }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
