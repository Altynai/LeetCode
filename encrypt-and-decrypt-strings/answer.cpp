const int N = 26;

class Encrypter {
  unordered_map<string, int> cnt;
  int where[N];
  vector<string> values;

public:
  Encrypter(vector<char> &keys, vector<string> &values,
            vector<string> &dictionary) {
    for (int i = 0; i < N; i++)
      where[i] = -1;
    for (int i = 0; i < (int)keys.size(); i++)
      where[keys[i] - 'a'] = i;
    this->values = values;

    cnt.clear();
    for (auto &s : dictionary)
      cnt[encrypt(s)]++;
  }

  string encrypt(string s) {
    string t = "";
    for (char ch : s) {
      int pos = where[ch - 'a'];
      t += values[pos];
    }
    return t;
  }

  int decrypt(string s) {
    auto it = cnt.find(s);
    return it == cnt.end() ? 0 : it->second;
  }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
