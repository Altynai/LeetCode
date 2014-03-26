
class Solution {
private:
    map<string, int> base_dict;
    map<string, int> curr_dict;

public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        base_dict.clear();
        for (int i = 0; i < L.size(); i++)
            base_dict[L[i]]++;
        if (base_dict.empty())
            return result;

        int n = S.size(), m = L[0].size(), count = L.size();
        for (int i = 0; i + m * count <= n; i++) {
            curr_dict.clear();
            bool not_valid = false;
            for (int j = 0; j < count; j++) {
                string word = S.substr(i + j * m, m);
                map<string, int>::iterator base_it = base_dict.find(word);
                if (base_it == base_dict.end()) {
                    not_valid = true;
                    break;
                }
                curr_dict[word]++;
                int curr_count = curr_dict[word];
                if (curr_count > (base_it->second)) {
                    not_valid = true;
                    break;
                }
            }
            if (!not_valid)
                result.push_back(i);
        }
        return result;
    }
};
