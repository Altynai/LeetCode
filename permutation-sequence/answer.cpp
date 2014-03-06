
class Solution {
private:
    void removeValue(vector<int> &nums, int index) {
        nums.erase(nums.begin() + index);
    }

    int factorial(int x) {
        int result = 1;
        while (x >= 1) {
            result *= x;
            x--;
        }
        return result;
    }

public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        string result = string(n, '0');
        for (int i = 0; i < n; i++) {
            int index = n - i;
            for (int j = 1; j <= n - i; j++) {
                // there are 'n - i' elements in nums
                int total = j * factorial(n - i - 1);
                if (total >= k) {
                    index = j;
                    if (j != 1)
                        k -= (j - 1) * factorial(n - i - 1);
                    break;
                }
            }
            index--;
            result[i] += nums[index];
            removeValue(nums, index);
        }
        return result;
    }
};