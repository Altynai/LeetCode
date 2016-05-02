class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream sin(str);
        string buffer;
        std::vector<string> strings;
        std::map<string, char> dict;
        std::map<char, string> reverse_dict;
        while (sin >> buffer)
            strings.push_back(buffer);
        if (pattern.length() != strings.size())
            return false;
        for (int i = 0; i < pattern.length(); ++i) {
            string token = strings[i];
            char word = pattern[i];
            std::map<string, char>::iterator it = dict.find(token);
            std::map<char, string>::iterator reverse_it = reverse_dict.find(word);
            if (it == dict.end() && reverse_it == reverse_dict.end()) {
                dict[token] = word;
                reverse_dict[word] = token;
            }
            else if (it->second != word || reverse_it->second != token)
                return false;
        }
        return true;
    }
};