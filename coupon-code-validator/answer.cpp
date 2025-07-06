class Solution {
public:
  bool isValidAlphanumericUnderscore(const std::string &str) {
    // Check if string is empty
    if (str.empty()) {
      return false;
    }

    // Check each character
    for (char c : str) {
      if (!std::isalnum(c) && c != '_') {
        return false;
      }
    }
    return true;
  }

  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    int n = code.size();
    const vector<string> categories = {"electronics", "grocery", "pharmacy",
                                       "restaurant"};
    unordered_map<string, vector<string>> coupons;
    for (auto c : categories)
      coupons[c] = {};

    for (int i = 0; i < n; i++) {
      if (!isActive[i])
        continue;
      if (coupons.count(businessLine[i]) == 0)
        continue;
      if (!isValidAlphanumericUnderscore(code[i]))
        continue;
      coupons[businessLine[i]].push_back(code[i]);
    }

    vector<string> ans;
    for (auto c : categories) {
      sort(coupons[c].begin(), coupons[c].end());
      ans.insert(ans.end(), coupons[c].begin(), coupons[c].end());
    }
    return ans;
  }
};
