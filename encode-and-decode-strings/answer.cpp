class Codec {
public:

    string encodeInteger(unsigned integer) {
        char buf[4];
        unsigned x = integer;
        for (int i = 3; i >= 0; --i) {
            buf[i] = (char)(integer & 0xFF);
            integer >>= 8;
        }
        return string(buf, buf + 4);
    }

    unsigned decodeInteger(const string& str) {
        unsigned integer = 0;
        for (int i = 0; i < 4; ++i) {
            integer |= (unsigned)(0xFF & str[i]);
            if (i != 3)
                integer <<= 8;
        }
        return integer;
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = encodeInteger(strs.size());
        for (int i = 0; i < strs.size(); ++i)
            ans += encodeInteger(strs[i].size()) + strs[i];
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        if (s.size() == 0)
            return ans;
        unsigned n = decodeInteger(s.substr(0, 4)), offset = 4;
        for (int i = 0; i < n; ++i) {
            unsigned length = decodeInteger(s.substr(offset, 4));
            offset += 4;
            if (length == 0)
                ans.push_back("");
            else {
                ans.push_back(s.substr(offset, length));
                offset += length;
            }
        }
        return ans;
    }
};
