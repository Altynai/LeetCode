class NumberContainers {
private:
  map<int, set<int>> at;
  map<int, int> val;

public:
  NumberContainers() {
    at.clear();
    val.clear();
  }

  void change(int index, int number) {
    auto it = val.find(index);
    if (it != val.end()) {
      int old = it->second;
      at[old].erase(index);
    }
    val[index] = number;
    at[number].insert(index);
  }

  int find(int number) {
    auto it = at.find(number);
    if (it == at.end() or it->second.size() == 0)
      return -1;
    return *(it->second.begin());
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
