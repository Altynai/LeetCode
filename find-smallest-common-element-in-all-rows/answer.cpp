class Solution {
    
private:
    bool all(vector<vector<int>>& mat, int val) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 1; i < n; i++) {
            auto it = lower_bound(mat[i].begin(), mat[i].end(), val);
            if (it == mat[i].end())
                return false;
            if (*it != val)
                return false;
        }
        return true;
    }

public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = 0; j < m; j++) {
            int val = mat[0][j];
            if (all(mat, val))
                return val;
        }
        return -1;
    }
};
