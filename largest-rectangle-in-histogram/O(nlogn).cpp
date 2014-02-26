#include "cmath"
#include "algorithm"
#include "vector"
#include "cstdio"
using namespace std;

class Solution {
private:
    void makeRQM(vector<int> &height, int **rmq, int n) {
        for (int i = 1; i <= n; i++)
            rmq[i][0] = i;
        for (int j = 1; j <= log((double)n) / log(2.0); j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                int _i = i + (1 << (j - 1));
                if (height[rmq[i][j - 1]] <= height[rmq[_i][j - 1]])
                    rmq[i][j] = rmq[i][j - 1];
                else
                    rmq[i][j] = rmq[_i][j - 1];
            }
        }
    }

    int getMinHeightIndex(vector<int> &height, int **rmq, int a, int b) {
        int k = (int) (log((double)b - a + 1) / log(2.0));
        int _a = b - (1 << k) + 1;
        if (height[rmq[a][k]] <= height[rmq[_a][k]])
            return rmq[a][k];
        else
            return rmq[_a][k];
    }

    void recursiveDivide(vector<int> &height, int low, int high, int **rmq, int &result) {
        if (low > high)
            return;
        int index = getMinHeightIndex(height, rmq, low, high);
        result = std::max(result, height[index] * (high - low + 1));
        recursiveDivide(height, low, index - 1, rmq, result);
        recursiveDivide(height, index + 1, high, rmq, result);
    }

public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0)
            return 0;
        height.insert(height.begin(), 0); // make index starts at 1
        int N = n + 1, M = (int)(log((double)n) / log(2.0)) + 1;
        int **rmq = new int *[N];
        for (int i = 0; i <= N; i++)
            rmq[i] = new int[M];
        makeRQM(height, rmq, n);
        int result = 0;
        recursiveDivide(height, 1, n, rmq, result);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution;
    int array[] = {5, 4, 1, 2};
    int n = sizeof(array) / sizeof(int);
    std::vector<int> v(array, array + n);
    printf("%d\n", solution->largestRectangleArea(v));
    return 0;
}