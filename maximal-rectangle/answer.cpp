
class Solution {
private:
    void calculateOneCount(vector<vector<char> > &matrix, int** count, int n, int m) {
        for (int i = 0; i < n; i++) {
            count[i][0] = (matrix[i][0] == '1');
            for (int j = 1; j < m; j++)
                count[i][j] = count[i][j - 1] + (matrix[i][j] == '1');
        }
    }

    void makeUnaryArray(int low, int high, int** count, int n, int array[]) {
        for (int i = 0; i < n; i++) {
            int sum = count[i][high];
            if (low)
                sum -= count[i][low - 1];
            array[i] = sum;
        }
    }

    int maxConsecutive(int array[], int n, int target) {
        int count = 0, result = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] == target) {
                count += 1;
                result = std::max(result, count);
            } else
                count = 0;
        }
        return result;
    }

public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        if ( n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        int **count = new int *[n];
        for (int i = 0; i < n; i++)
            count[i] = new int[m];
        calculateOneCount(matrix, count, n, m);
        int *array = new int[n], result = 0;
        for (int low = 0; low < m; low++) {
            for (int high = low; high < m; high++) {
                makeUnaryArray(low, high, count, n, array);
                int target = high - low + 1;
                int max_length =  maxConsecutive(array, n, target);
                result = std::max(result, max_length * target);
            }
        }
        return result;
    }
};