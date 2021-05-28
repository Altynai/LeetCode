class FindSumPairs {
private:
  map<int, int> cnt;
  vector<int> nums1;
  vector<int> nums2;

public:
  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    cnt.clear();
    for (int v : nums2)
      cnt[v] += 1;
  }

  void add(int index, int val) {
    cnt[nums2[index]]--;
    cnt[nums2[index] += val]++;
  }

  int count(int tot) {
    int ans = 0;
    for (int v : nums1) {
      auto it = cnt.find(tot - v);
      if (it != cnt.end())
        ans += it->second;
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
