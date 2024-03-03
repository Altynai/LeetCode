class Solution {
public:
  vector<int> resultArray(vector<int> &a) {
    vector<int> arr1 = {a[0]}, arr2 = {a[1]};
    int n = a.size();
    for (int i = 2; i < n; i++) {
      if (arr1.back() > arr2.back())
        arr1.push_back(a[i]);
      else
        arr2.push_back(a[i]);
    }
    for (int x : arr2)
      arr1.push_back(x);
    return arr1;
  }
};
