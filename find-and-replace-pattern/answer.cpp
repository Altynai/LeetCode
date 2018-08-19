bool check(const string& word, const string& pattern) {
    map<char, char> f, g;
    for (int i = 0; i < word.size(); i++) {
        auto j = f.find(word[i]);
        if (j != f.end() && j->second != pattern[i])
            return false;
        auto k = g.find(pattern[i]);
        if (k != g.end() && k->second != word[i])
            return false;
        f[word[i]] = pattern[i];
        g[pattern[i]] = word[i];
    }
    return true;
}

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto predicate = [pattern](const string& word) {return check(word, pattern);};
        copy_if(words.begin(), words.end(), back_inserter(ans), predicate);
        return ans;
    }
};
