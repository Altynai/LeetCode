
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int count = prices.size();
        if (count == 0 )
            return 0;

        int *high = new int[count];
        int *low = new int[count];

        low[0] = prices[0];
        for (int i = 1; i < count; i++)
            low[i] = std::min(low[i - 1], prices[i]);
        high[count - 1] = prices[count - 1];
        for (int i = count - 2; i >= 0; i--)
            high[i] = std::max(high[i + 1], prices[i]);
        int result = 0;
        for (int i = 0; i < count - 1; i++)
            result = std::max(result, high[i + 1] - low[i]);
        return result;
    }
};