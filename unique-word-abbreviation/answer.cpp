#define Key pair<char, pair<int, char>>

class ValidWordAbbr {
public:
    set<string> words;
    map<Key, int> mapping;

    ValidWordAbbr(vector<string> dictionary) {
        mapping.clear();
        words.clear();
        for (int i = 0; i < dictionary.size(); ++i) {
            string word = dictionary[i];
            if (words.find(word) != words.end())
                continue;
            Key key = computeKey(word);
            mapping[key]++;
            words.insert(word);
        }
    }

    Key computeKey(string& word) {
        int n = word.size();
        char first = word[0];
        char last = word[n - 1];
        return make_pair(first, make_pair(n - 2, last));
    }

    bool isUnique(string word) {
        Key key = computeKey(word);
        auto it = mapping.find(key);

        if (words.find(word) == words.end())
            return it == mapping.end();
        else
            return it -> second <= 1;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */