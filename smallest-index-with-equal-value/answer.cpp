class Solution {
public:
  int smallestEqual(vector<int> &a) {
    for (int i = 0; i < a.size(); i++)
      if (i % 10 == a[i])
        return i;
    return -1;
  }
};
