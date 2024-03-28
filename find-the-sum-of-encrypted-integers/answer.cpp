class Solution {
public:
  int sumOfEncryptedInt(vector<int> &a) {
    int ans = 0;
    for (int x : a) {
      string s = to_string(x);
      char ch = *max_element(s.begin(), s.end());
      ans += stoi(string(s.size(), ch));
    }
    return ans;
  }
};
