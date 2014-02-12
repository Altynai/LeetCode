
class Solution {
public:
    int candy(vector<int> &ratings) {
        int children_count = ratings.size();
        if (children_count == 0)
            return 0;
        int *high = new int[children_count];
        for (int i = 0; i < children_count; i++)
            high[i] = 1;

        // from left to right
        for (int i = 1; i < children_count; i++) {
            if (ratings[i] > ratings[i - 1])
                high[i] = std::max(high[i], high[i - 1] + 1);
        }
        // from right to left
        for (int i = children_count - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                high[i] = std::max(high[i], high[i + 1] + 1);
        }
        int result = 0;
        for (int i = 0; i < children_count; i++)
            result += high[i];
        delete [] high;
        return result;
    }
};
