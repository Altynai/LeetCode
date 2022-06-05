#define sz(a) ((int)(a).size())

class TextEditor {
private:
  deque<char> l, r;

  string last() {
    string ans;
    int m = min(10, sz(l));
    for (auto it = l.rbegin(); m > 0; m--, it++)
      ans.push_back(*it);
    reverse(ans.begin(), ans.end());
    return ans;
  }

public:
  TextEditor() {}

  void debug() {
    string left = string(l.begin(), l.end());
    string right = string(r.begin(), r.end());
    cout << left << " " << right << endl;
  }

  void addText(string text) {
    for (char ch : text)
      l.push_back(ch);
  }

  int deleteText(int k) {
    int ans = 0;
    while (k > 0 and sz(l)) {
      ans++, k--;
      l.pop_back();
    }
    return ans;
  }

  string cursorLeft(int k) {
    while (k > 0 and sz(l)) {
      char ch = l.back();
      l.pop_back();
      r.push_front(ch);
      k--;
    }
    return last();
  }

  string cursorRight(int k) {
    while (k > 0 and sz(r)) {
      char ch = r.front();
      r.pop_front();
      l.push_back(ch);
      k--;
    }
    return last();
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
