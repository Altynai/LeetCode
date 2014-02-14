#include "vector"
#include "cstdio"
using namespace std;

class Solution {
private:
    static const int MAX_PRICE = 0x7fffffff;
    static const int MIN_PRICE = -0x7fffffff;

public:
    int maxProfit(vector<int> &prices) {
        int count = prices.size();
        if (count == 0 )
            return 0;
        int *left_profit = new int[count];
        int *right_profit = new int[count];
        int low = MAX_PRICE, high = MIN_PRICE;
        for (int i = 0; i < count; i++) {
            if (low != MAX_PRICE)
                left_profit[i] = std::max(0, prices[i] - low);
            else
                left_profit[i] = 0;
            low = std::min(low, prices[i]);
        }
        for (int i = count - 1; i >= 0; i--) {
            if (high != MIN_PRICE)
                right_profit[i] = std::max(0, high - prices[i]);
            else
                right_profit[i] = 0;
            if (i + 1 < count)
                right_profit[i] = std::max(right_profit[i], right_profit[i + 1]);
            high = std::max(high, prices[i]);
        }
        int result = 0;
        for (int i = 0; i < count; i++) {
            result = std::max(result, left_profit[i]);
            if (i + 1 < count)
                result = std::max(result, left_profit[i] + right_profit[i + 1]);
        }
        // for (int i = 0; i < count; i++)
        //     printf("%d %d\n", left_profit[i], right_profit[i]);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    // int a[] = {1, 2};
    int a[] = {3, 2, 6, 5, 0, 3};
    int n = sizeof(a) / sizeof(int);
    vector<int> v(a, a + n);
    printf("%d\n", solution->maxProfit(v));
    return 0;
}