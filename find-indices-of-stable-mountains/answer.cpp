class Solution {
public:
  vector<int> stableMountains(vector<int> &height, int threshold) {
    vector<int> ans;
    int n = height.size();
    for (int i = 1; i < n; i++) {
      if (height[i - 1] > threshold)
        ans.push_back(i);
    }
    return ans;
  }
};
