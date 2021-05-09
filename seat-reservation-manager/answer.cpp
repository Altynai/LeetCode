class SeatManager {
private:
  set<int> available;

public:
  SeatManager(int n) {
    available.clear();
    for (int i = 0; i < n; i++)
      available.insert(i);
  }

  int reserve() {
    int ans = *available.begin();
    available.erase(available.begin());
    return ans + 1;
  }

  void unreserve(int seatNumber) { available.insert(seatNumber - 1); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
