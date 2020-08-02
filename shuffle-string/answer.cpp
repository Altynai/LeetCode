class Solution {
public:
    string restoreString(string s, vector<int>& a) {
        string t = s;
        for (int i = 0; i < a.size(); i++) t[a[i]] = s[i];
        return t;
    }
};
