int common(const string &lh, const string &rh) {
    int n = std::min(lh.size(), rh.size());
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (lh[i] == rh[i])
            len++;
        else
            break;
    }
    return len;
}

int compare(const string &lh, const string &rh) {
    if (lh == rh)
        return 0;

    if (lh.size() == 1 || rh.size() == 1) {
        if (lh.size() == 1) {
            for (int i = 0; i < rh.size(); i++) {
                if (lh[0] != rh[i])
                    return lh[0] < rh[i] ? -1 : 1;
            }
        } else {
            for (int i = 0; i < lh.size(); i++) {
                if (rh[0] != lh[i])
                    return lh[i] < rh[0] ? -1 : 1;
            }
        }
        return 0;
    }

    int common_len = common(lh, rh);
    if (common_len == 0)
        return lh < rh ? -1 : 1;
    else if (common_len == lh.size())
        return compare(lh, rh.substr(common_len));
    else if (common_len == rh.size())
        return compare(lh.substr(common_len), rh);
    else
        return compare(lh.substr(common_len), rh.substr(common_len));
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> s_num;
        for (int i = 0; i < num.size(); ++i)
            s_num.push_back(std::to_string(num[i]));

        for (int i = 0; i < s_num.size(); ++i) {
            for (int j = i + 1; j < s_num.size(); ++j) {
                if (compare(s_num[i], s_num[j]) == 1)
                    std::swap(s_num[i], s_num[j]);
            }
        }

        string result = "";
        for (int i = s_num.size() - 1; i >= 0; i--)
            result += s_num[i];

        int index = 0;
        for (int i = 0; i + 1 < result.size(); i++) {
            if (result[i] == '0' && result[i + 1] == '0')
                index ++;
            else
                break;
        }
        return result.substr(index);
    }
};