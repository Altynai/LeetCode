class Solution {
public:
  string evaluate(string s, vector<vector<string>> &knowledge) {
    map<string, string> k;
    for (auto &v : knowledge)
      k[v[0]] = v[1];

    string ans = "";
    int n = s.size();
    for (int i = 0; i < n;) {
      if (s[i] != '(')
        ans += s[i++];
      else {
        int j = i;
        while (s[j] != ')')
          j++;
        string name = s.substr(i + 1, j - 1 - (i + 1) + 1);
        string val = "?";
        if (k.count(name))
          val = k[name];
        ans += val;
        i = j + 1;
      }
    }
    return ans;
  }
};
