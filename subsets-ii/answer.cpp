
class Solution {
private:
    vector<int> makeVector(vector<int> &num, vector<int> &used, int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < used[i]; j++)
                result.push_back(num[i]);
        }
        return result;
    }

    void dfs(vector<vector<int> > &result, vector<int> &num, vector<int> &count, vector<int> &used, int index, int n) {
        if (index == n) {
            result.push_back(makeVector(num, used, n));
            return;
        }
        for (int i = 0; i <= count[index]; i++) {
            used[index] = i;
            dfs(result, num, count, used, index + 1, n);
        }
    }

    int unique(vector<int> &num, vector<int> &count, int n) {
        if (n == 0)
            return n;
        int m = 1;
        count[0] = 1;
        for (int i = 1; i < n; i++) {
            if (num[i] == num[m - 1])
                count[m - 1]++;
            else {
                num[m] = num[i];
                count[m++] = 1;
            }
        }
        return m;
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int n = S.size();
        std::sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> count(n, 0);
        vector<int> used(n, 0);

        n = unique(S, count, n);
        dfs(result, S, count, used, 0, n);
        return result;
    }
};
