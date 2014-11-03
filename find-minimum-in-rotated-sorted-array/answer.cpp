
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int result = num[0];

        if (n == 1)
            return result;

        int low = 0, mid, high = n - 1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (num[mid] >= num[0]) {
                low = mid + 1;
            } else {
                result = std::min(result, num[mid]);
                high = mid - 1;
            }
        }
        return result;
    }
};