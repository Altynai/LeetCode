class Solution {
public:
    char shift(const char& chr, int diff) {
        int d = chr - 'a';
        if (diff <= d)
            return (char)(chr - diff);
        return (char)('z' - (diff - d - 1));
    }

    string transform(const string& word) {
        int n = word.size();
        if (n == 0)
            return "";
        else if (n == 1)
            return "a";
        else if (word[0] == 'a')
            return word;
        else {
            string copy(word.begin(), word.end());
            int diff = word[0] - 'a';
            for (int i = 0; i < n; ++i)
                copy[i] = shift(copy[i], diff);
            return copy;
        }
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> items;
        for (int i = 0; i < strings.size(); ++i)
            items[transform(strings[i])].push_back(strings[i]);
        vector<vector<string>> ans;
        for (auto i = items.begin(); i != items.end(); ++i)
            ans.push_back(i->second);
        return ans;
    }
};