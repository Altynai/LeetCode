class Solution {
public:
    void flip(char& chr) {
        chr = (chr == '+') ? '-' : '+';
    }

    vector<string> generatePossibleNextMoves(string s) {
        set<string> db;
        int n = s.size();
        if (n <= 1)
            return vector<string>();
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i] || s[i] == '-')
                continue;
            flip(s[i - 1]), flip(s[i]);
            db.insert(s);
            flip(s[i - 1]), flip(s[i]);
        }
        return vector<string>(db.begin(), db.end());
    }
};