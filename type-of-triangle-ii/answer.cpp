class Solution {
public:
  string triangleType(vector<int> &a) {
    sort(a.begin(), a.end());
    if (a[0] + a[1] <= a[2])
      return "none";
    else if (a[0] == a[2])
      return "equilateral";
    else if (a[0] == a[1] or a[1] == a[2])
      return "isosceles";
    return "scalene";
  }
};
