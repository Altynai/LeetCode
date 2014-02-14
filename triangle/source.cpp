#include "vector"
#include "cstdio"
using namespace std;

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

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int> > v;
    std::vector<int> t;
    t.push_back(-1);
    v.push_back(t);
    std::vector<int> t2;
    t2.push_back(2);
    t2.push_back(3);
    v.push_back(t2);
    std::vector<int> t3;
    t3.push_back(1);
    t3.push_back(-1);
    t3.push_back(-3);
    v.push_back(t3);
    Solution *s = new Solution();
    printf("%d\n", s->minimumTotal(v));
    return 0;
}