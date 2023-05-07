class FrequencyTracker {
private:
  unordered_map<int, int> freq;
  multiset<int> cnt;

public:
  FrequencyTracker() {}

  void add(int number) {
    int x = freq[number]++;
    auto it = cnt.find(x);
    if (it != cnt.end())
      cnt.erase(it);
    cnt.insert(x + 1);
  }

  void deleteOne(int number) {
    auto it = freq.find(number);
    if (it == freq.end() or it->second == 0)
      return;

    int x = it->second--;
    cnt.erase(cnt.find(x));
    if (x > 1)
      cnt.insert(x - 1);
  }

  bool hasFrequency(int frequency) { return cnt.find(frequency) != cnt.end(); }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
