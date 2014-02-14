
class Solution {
private:
    static const int MAX_INT = 0x7fffffff;

public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int deepth = triangle.size();
        if (deepth == 1)
            return triangle[0][0];
        int sum[1] = {triangle[0][0]};
        return findMinPathSum(triangle, 1, sum, 1);
    }

private:
    int findMinPathSum(vector<vector<int> > &triangle, int deepth, int sum[], int n) {
        if (deepth == triangle.size()) {
            int result = MAX_INT;
            for (int i = 0; i < n; ++i)
                result = std::min(result, sum[i]);
            return result;
        }
        int *new_sum = new int [n + 1];
        for (int i = 0; i < n + 1; i++)
            new_sum[i] = MAX_INT;
        for (int i = 0; i < triangle[deepth].size(); i++) {
            int val = triangle[deepth][i];
            if (i)
                new_sum[i] = std::min(new_sum[i], sum[i - 1] + val);
            if (i < n)
                new_sum[i] = std::min(new_sum[i], sum[i] + val);
        }
        return findMinPathSum(triangle, deepth + 1, new_sum, n + 1);
    }
};