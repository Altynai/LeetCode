class Solution {
private:
    map<int, string> replace;
    map<int, int> lens;

    bool match(string& S, int index, string& source) {
        int n = S.size(), m = source.size();
        int i = index, j = 0;
        while (i < n && j < m && S[i] == source[j])
            i++, j++;
        return j == m;
    }

public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        replace.clear();
        lens.clear();
        int n = indexes.size();
        for (int i = 0; i < n; i++) {
            if (match(S, indexes[i], sources[i])) {
                replace[indexes[i]] = targets[i];
                lens[indexes[i]] = sources[i].size();
            }
        }
        vector<char> ans;
        for (int i = 0; i < S.size(); ) {
            auto it = replace.find(i);
            if (it == replace.end()) {
                ans.push_back(S[i]);
                i++;
            }
            else {
                for (char chr : it->second)
                    ans.push_back(chr);
                i += lens[i];
            }
        }
        return string(ans.begin(), ans.end());
    }
};
