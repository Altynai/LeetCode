const int N = 10;

class WordFilter {
private:
  unordered_map<string, unordered_map<string, int>> dict;

public:
  WordFilter(vector<string> words) {
    dict.clear();
    for (int k = 0; k < words.size(); k++) {
      int len = (int)words[k].size();
      int n = min(N, len);
      for (int i = 1; i <= n; i++) {
        string pfx = words[k].substr(0, i);
        for (int j = 1; j <= n; j++) {
          string sfx = words[k].substr(len - j, j);
          int weight = dict[pfx][sfx];
          dict[pfx][sfx] = max(k, weight);
        }
      }
    }
  }

  int f(string prefix, string suffix) {
    auto it = dict.find(prefix);
    if (it == dict.end())
      return -1;

    auto &d = it->second;
    if (d.count(suffix))
      return d[suffix];
    else
      return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
