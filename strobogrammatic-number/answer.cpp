class Solution {
public:
    bool valid(const char& lh, const char& rh) {
        if (lh == '6')
            return rh == '9';
        if (lh == '9')
            return rh == '6';
        if (lh == '1' || lh == '8' || lh == '0')
            return lh == rh;
        return false;
    }

    bool isStrobogrammatic(string num) {
        int n = num.size();
        if (n == 0)
            return true;
        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
            if (!valid(num[i], num[j]))
                return false;
        }
        return true;
    }
};