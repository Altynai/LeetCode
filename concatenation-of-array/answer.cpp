class Solution {
public:
  vector<int> getConcatenation(vector<int> &a) {
    vector<int> b = a;
    b.insert(b.end(), a.begin(), a.end());
    return b;
  }
};
