class Solution {
private:
    bool isGreater(int a, int b) {
        return a == -1 || a > b;
    }

    int closestInRange(vector<int> &num, int low, int high, int target) {
        int value = -1, mid = high, index = -1, _low = low;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (target <= num[mid]) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (index != -1) {
            value = num[index];
            if (index + 1 <= high && isGreater(std::abs(target - value), num[index + 1] - target))
                value = num[index + 1];
        } else {
            if (_low <= high)
                value = num[high];
        }
        return value;
    }

public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        std::sort(num.begin(), num.end());
        int result = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int value = closestInRange(num, j + 1, n - 1, target - num[i] - num[j]);
                if (value != -1) {
                    value += num[i] + num[j];
                    if (i == 0 && j == 1)
                        result = value;
                    else if (std::abs(target - value) < std::abs(target - result)) {
                        result = value;
                    }
                }
            }
        }
        return result;
    }
};