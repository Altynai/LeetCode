class LUPrefix {
  int n;
  vector<bool> seen;
  int ans;

public:
  LUPrefix(int n) {
    this->n = n;
    seen = vector<bool>(n + 1, 0);
    ans = 0;
  }

  void upload(int video) {
    seen[video] = 1;
    while (seen[ans + 1])
      ans++;
  }

  int longest() { return ans; }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
