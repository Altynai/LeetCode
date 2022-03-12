mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define randomInt(a, b) uniform_int_distribution<int>((a), (b))(rng)

class RandomizedCollection {
  unordered_map<int, unordered_set<int>> pos;
  vector<int> v;
  int n;

public:
  RandomizedCollection() {
    pos.clear();
    n = 0;
    v.clear();
  }

  bool insert(int val) {
    if (n == v.size())
      v.push_back(val), n++;
    else
      v[n++] = val;

    pos[val].insert(n - 1);
    return pos[val].size() == 1;
  }

  bool remove(int val) {
    auto it = pos.find(val);
    if (it == pos.end() or (it->second).size() == 0)
      return false;

    // swap with the back element
    auto &where = it->second;
    int p = *where.begin();
    where.erase(where.begin());

    if (p < n - 1) {
      v[p] = v[n - 1];
      pos[v[n - 1]].erase(n - 1);
      pos[v[n - 1]].insert(p);
    }

    n -= 1;
    return true;
  }

  int getRandom() { return v[randomInt(0, n - 1)]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
