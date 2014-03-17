
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        std::map<string, vector<string> > hash;
        for (int i = 0; i < strs.size(); i++) {
            string backup = strs[i];
            std::sort(backup.begin(), backup.end());
            if (hash.find(backup) == hash.end())
                hash[backup] = vector<string>();
            hash[backup].push_back(strs[i]);
        }
        vector<string> result;
        for (map<string, vector<string> >::iterator i = hash.begin(); i != hash.end(); i++) {
            const vector<string> &strings = i->second;
            if (strings.size() > 1)
                result.insert(result.end(), strings.begin(), strings.end());
        }
        return result;
    }
};