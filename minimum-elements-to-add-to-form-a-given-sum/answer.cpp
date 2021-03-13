class Solution {
public:
  int minElements(vector<int> &nums, int limit, int goal) {
    long long sum = 0;
    for (int num : nums)
      sum += num;
    long long d = abs(sum - goal);
    return (d + limit - 1) / limit;
  }
};
