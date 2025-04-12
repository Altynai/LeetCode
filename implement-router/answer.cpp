class Router {
  int memoryLimit;

  set<vector<int>> seen;
  deque<vector<int>> packs;

  unordered_map<int, vector<int>> dst_timestamps;
  unordered_map<int, int> top;

public:
  Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    vector<int> pack = {source, destination, timestamp};
    if (seen.count(pack))
      return 0;

    if (seen.size() == memoryLimit)
      forwardPacket();

    seen.insert(pack);
    packs.push_back(pack);
    dst_timestamps[destination].push_back(timestamp);
    return 1;
  }

  vector<int> forwardPacket() {
    if (packs.size() == 0)
      return {};

    vector<int> pack = packs.front();
    packs.pop_front();

    seen.erase(pack);
    top[pack[1]]++;

    return pack;
  }

  int getCount(int destination, int startTime, int endTime) {
    const vector<int> &v = dst_timestamps[destination];
    int i = top[destination], n = v.size();

    int l = lower_bound(v.begin() + i, v.end(), startTime) - v.begin();
    if (l == n)
      return 0;
    int r = upper_bound(v.begin() + i, v.end(), endTime) - v.begin() - 1;
    return r < l ? 0 : r - l + 1;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
