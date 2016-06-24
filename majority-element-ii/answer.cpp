#define NOT_FOUND -1

class Solution {
private:
    int findExistElement(vector<int>& elements, vector<int>& counter, int value) {
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == value && counter[i] > 0)
                return i;
        }
        return NOT_FOUND;
    }

    int findSlot(vector<int>& counter) {
        for (int i = 0; i < counter.size(); ++i) {
            if (counter[i] == 0)
                return i;
        }
        return NOT_FOUND;
    }

    void decr(vector<int>& counter) {
        for (int i = 0; i < counter.size(); ++i)
            counter[i]--;
    }

    int count(vector<int>& elements, int value) {
        int result = 0;
        for (int i = 0; i < elements.size(); ++i) {
            if (elements[i] == value)
                result++;
        }
        return result;
    }

public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums;
        vector<int> counter(3, 0);
        vector<int> elements(3, 0);
        for (int i = 0; i < n; ++i) {
            int pos = findExistElement(elements, counter, nums[i]);
            if (pos == NOT_FOUND) {
                pos = findSlot(counter);
                if (pos == NOT_FOUND)
                    decr(counter);
                else {
                    counter[pos] = 1;
                    elements[pos] = nums[i];
                }
            } else
                counter[pos]++;
        }
        vector<int> result;
        for (int i = 0; i < elements.size(); ++i) {
            if (counter[i] > 0 && count(nums, elements[i]) > n / 3)
                result.push_back(elements[i]);
        }
        return result;
    }
};