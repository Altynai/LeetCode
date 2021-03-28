class Solution {
public:
  int numDifferentIntegers(string s) {
    set<string> seen;
    int n = s.size();

    for (int i = 0; i < n;) {
      if (!isdigit(s[i]))
        i++;
      else {
        int j = i;
        while (j < n && isdigit(s[j]))
          j++;
        int k = i;
        while (k < j && s[k] == '0')
          k++;
        seen.insert(s.substr(k, j - k));
        i = j;
      }
    }
    return seen.size();
  }
};
