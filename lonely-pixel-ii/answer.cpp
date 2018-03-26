#define uint_64 unsigned long long

class Solution {
private:
    vector<int> rowCounter;
    vector<int> colCounter;
    vector<uint_64> rowHash;
    vector<vector<int>> colLinker;
    int n, m;
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        int m = n ? picture[0].size() : 0;
        if (n == 0 || m == 0)
            return 0;
        rowHash = vector<uint_64>(n, 0);
        rowCounter = vector<int>(n, 0);
        colCounter = vector<int>(m, 0);
        colLinker = vector<vector<int>>(m, vector<int>());
        for (int i = 0; i < n; ++i) {
            uint_64 hash = 0;
            for (int j = 0; j < m; ++j) {
                hash = hash * 101 + (int)picture[i][j];
                if (picture[i][j] == 'B') {
                    rowCounter[i]++;
                    colCounter[j]++;
                }
            }
            rowHash[i] = hash;
        }
        for (int j = 0; j < m; ++j) {
            if (colCounter[j] != N)
                continue;
            for (int i = 0; i < n; ++i) {
                if (picture[i][j] == 'B')
                    colLinker[j].push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] != 'B')
                    continue;
                if (rowCounter[i] != N)
                    continue;
                if (colCounter[j] != N)
                    continue;
                bool same = true;
                for (int k = 0; k < colLinker[j].size(); k++) {
                    int r = colLinker[j][k];
                    if (rowHash[r] != rowHash[i]) {
                        same = false;
                        break;
                    }
                }
                ans += same ? 1 : 0;
            }
        }
        return ans;
    }
};