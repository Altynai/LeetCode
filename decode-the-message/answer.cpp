class Solution {
public:
  string decodeMessage(string key, string message) {
    map<char, char> m;
    char now = 'a';
    for (char k : key)
      if (k != ' ' and m.count(k) == 0)
        m[k] = now++;

    string ans = message;
    for (char &c : ans)
      if (c != ' ')
        c = m[c];
    return ans;
  }
};
