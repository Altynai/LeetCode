#include "vector"
#include "cstdio"
using namespace std;

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

int main(int argc, char const *argv[]) {
    int ratings[2] = {2, 1};
    Solution *solution = new Solution();
    vector<int> v(ratings, ratings + 2);
    printf("%d\n", solution->candy(v));
    return 0;
}