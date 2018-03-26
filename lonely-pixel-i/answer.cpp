class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size(), m = picture.size() ? picture[0].size() : 0;
        if (n == 0 || m == 0)
            return 0;
        vector<int> row(n, 0);
        vector<int> column(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B')
                    row[i]++, column[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && column[j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};