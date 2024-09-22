class Solution {
public:
  bool reportSpam(vector<string> &message, vector<string> &bannedWords) {
    unordered_set<string> s(bannedWords.begin(), bannedWords.end());
    for (int i = 0, cnt = 0; i < message.size(); i++) {
      if (s.count(message[i]))
        cnt++;
      if (cnt == 2)
        return 1;
    }
    return 0;
  }
};
