class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> counter;
        for (int i = 0; i < t.size(); ++i)
            counter[t[i]]++;
        for (int i = 0; i < s.size(); ++i)
            counter[s[i]]--;
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            if (it->second == 1)
                return it->first;
        }
        return 'a';
    }
};