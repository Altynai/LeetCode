const int N = 26;

struct Counter {
  vector<int> freq;
  int uniq;

  Counter() {}
  Counter(const string &s) {
    freq = vector<int>(N, 0);
    uniq = 0;

    for (char c : s)
      add(c - 'a');
  }

  void add(int x) {
    if (freq[x]++ == 0)
      uniq++;
  }

  void remove(int x) {
    if (--freq[x] == 0)
      uniq--;
  }

  int swap(int x, int y) {
    remove(x), add(y);
    int ans = uniq;
    remove(y), add(x);
    return ans;
  }
};

class Solution {
public:
  bool isItPossible(string word1, string word2) {
    Counter a(word1), b(word2);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (a.freq[i] and b.freq[j] and a.swap(i, j) == b.swap(j, i))
          return 1;
      }
    }
    return 0;
  }
};
