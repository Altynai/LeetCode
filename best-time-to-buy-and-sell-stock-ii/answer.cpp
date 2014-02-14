
class Solution {
private:
    static const int MAX_PRICE = 0x7fffffff;
    static const int MIN_PRICE = -0x7fffffff;

public:
    int maxProfit(vector<int> &prices) {
        int count = prices.size();
        if (count == 0 )
            return 0;
        int result = 0, i = 0;
        int min_price = MAX_PRICE, max_price = MIN_PRICE;
        while (i < count) {
            min_price = MAX_PRICE, max_price = MIN_PRICE;
            while (i < count && prices[i] <= min_price) {
                min_price = prices[i];
                i++;
            }
            while (i < count && prices[i] >= max_price) {
                max_price = prices[i];
                i++;
            }
            if (min_price != MAX_PRICE && max_price != MIN_PRICE)
                result += max_price - min_price;
        }
        return result;
    }
};
