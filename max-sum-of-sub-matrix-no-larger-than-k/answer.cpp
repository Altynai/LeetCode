class Solution {
private:
    int n, m;
    vector<vector<int> > sum;

    void init(vector<vector<int> >& matrix) {
        n = matrix.size();
        if (n == 0)
            return;
        m = matrix[0].size();
        sum = vector<vector<int> >(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            sum[i][0] = matrix[i][0];
            for (int j = 1; j < m; ++j)
                sum[i][j] = sum[i][j - 1] + matrix[i][j];
        }
    }

    int findClosest(set<int>& si, int value, int closest, int k) {
        if (value <= k && (closest > k || value > closest))
            closest = value;
        if (si.size() == 0)
            return closest;
        set<int>::iterator it = si.begin();
        // find max value x, value - x <= k
        // x >= value - k
        it = si.lower_bound(value - k);
        if (it == si.end())
            return closest;
        else {
            value = value - *it;
            if (value <= k && (closest > k || value > closest))
                closest = value;
            return closest;
        }
    }

    int sumSubmatrix(int l, int r, int k) {
        set<int> si;
        int closest = k + 1, value = 0;
        for (int i = 0; i < n; ++i) {
            if (l == 0)
                value += sum[i][r];
            else
                value += sum[i][r] - sum[i][l - 1];
            closest = findClosest(si, value, closest, k);
            si.insert(value);
        }
        return closest;
    }

public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        init(matrix);
        if (n == 0)
            return 0;
        int closest = k + 1;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                int value = sumSubmatrix(i, j, k);
                if (value <= k && (closest > k || value > closest))
                    closest = value;
            }
        }
        return closest;
    }
};